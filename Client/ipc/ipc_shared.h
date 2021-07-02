#pragma once
#include <cwchar>
struct s_mbuffer
{
	char m[0x512];
};
namespace ipc::shared
{
	namespace internal
	{
		enum eDirection : unsigned char
		{
			REQ,
			RET
		};
		enum eRequestId : unsigned char
		{
			shutdown,
			ping,
			getmodulebase,
			readmem,
			writemem
		};
	}
}

namespace ipc::shared
{
	template <
		internal::eDirection dir,
		internal::eRequestId req
	>
		struct tbuf;

	template <
		internal::eDirection dir
	>
		struct tbuf<dir, internal::eRequestId::ping>
	{
		char data[5];
	};

	template <
		internal::eDirection dir
	>
		struct tbuf<dir, internal::eRequestId::shutdown>
	{
		bool done;
	};

	template <
		internal::eDirection dir
	>
		struct tbuf<dir, internal::eRequestId::getmodulebase>
	{};
	template <>
	struct tbuf<internal::eDirection::REQ, internal::eRequestId::getmodulebase>
	{
		char	target[0xFF];
		wchar_t mem_target[0xFF];
	};
	template <>
	struct tbuf<internal::eDirection::RET, internal::eRequestId::getmodulebase>
	{
		unsigned long long target;
		unsigned long long address;
		unsigned long long max_address;
	};

	template <
		internal::eDirection dir
	>
		struct tbuf<dir, internal::eRequestId::readmem> {};
	template <>
	struct tbuf<internal::eDirection::REQ, internal::eRequestId::readmem>
	{
		unsigned long long target;
		unsigned long long address;
		unsigned long long size;
	};
	template <>
	struct tbuf<internal::eDirection::RET, internal::eRequestId::readmem>
	{
		unsigned long read;
		unsigned char buf[0x100];
	};

	template <
		internal::eDirection dir
	>
		struct tbuf<dir, internal::eRequestId::writemem> {};
	template <>
	struct tbuf<internal::eDirection::REQ, internal::eRequestId::writemem>
	{
		unsigned long long target;
		unsigned long long address;
		unsigned long long size;
		unsigned char buf[0x100];
	};
	template <>
	struct tbuf<internal::eDirection::RET, internal::eRequestId::writemem>
	{
		unsigned long written;
	};

	
}


/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

namespace ipc::shared
{
	struct tPacketHeader
	{
		internal::eDirection	direction;
		internal::eRequestId	request_id;
		unsigned long long		size;
	};
	template
		<
		internal::eDirection	dir,
		internal::eRequestId	req,
		internal::eDirection	ndir = dir == internal::eDirection::RET ? internal::eDirection::REQ : internal::eDirection::RET
		>
		struct tPacket
	{
		const tPacketHeader		header = { dir, req, sizeof(tPacket<ndir, req>) };
		tPacket<ndir, req>*		brother;
		union uData
		{
			tbuf<dir, req>		obj;
		}						data;
	};
	constexpr unsigned _multipacket_count = 10;
	struct tMultiPacket
	{
		unsigned						count = 0;
		const unsigned					count_max = _multipacket_count;
		struct tMultiPacketHeader
		{
			unsigned long long			handle = 0;
			shared::tPacketHeader*		pdata = nullptr;
		}								ahead[_multipacket_count];
	};
}