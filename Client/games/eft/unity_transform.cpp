#include <inc.hpp>

games::c_vector3 games::eft::c_transform::get_position()
{
	uint64_t transform_internal = games::c_phys_util::Instance().phys_read<uint64_t>(this->base + 0x10);
	if (!transform_internal)
		return games::c_vector3(0, 0, 0);

	uint64_t some_ptr = games::c_phys_util::Instance().phys_read<uint64_t>(transform_internal + 0x38);
	if (!some_ptr) return {};

	int32_t index = games::c_phys_util::Instance().phys_read<int32_t>(transform_internal + 0x38 + 0x8);
	if (!some_ptr)
	    return games::c_vector3(0, 0, 0);

	auto relation_array = games::c_phys_util::Instance().phys_read<uint64_t>(some_ptr + 0x18);
	if (!relation_array)
	    return games::c_vector3(0, 0, 0);

	uint64_t dependency_index_array = games::c_phys_util::Instance().phys_read<uint64_t>(some_ptr + 0x20);
	if (!dependency_index_array)
	    return games::c_vector3(0, 0, 0);

	__m128 result;

	const __m128 mulVec0 = { -2.000, 2.000, -2.000, 0.000 };
	const __m128 mulVec1 = { 2.000, -2.000, -2.000, 0.000 };
	const __m128 mulVec2 = { -2.000, -2.000, 2.000, 0.000 };

	result = games::c_phys_util::Instance().phys_read<__m128>(relation_array + 0x30 * index);

	int transformIndex = games::c_phys_util::Instance().phys_read<int>((uint64_t)dependency_index_array + 0x4 * index);
	int loop = 0;
	while (transformIndex >= 0)
	{
	    Matrix34 matrix34 = games::c_phys_util::Instance().phys_read<Matrix34>((uint64_t)relation_array + 0x30 * transformIndex);

	    __m128 xxxx = _mm_castsi128_ps(_mm_shuffle_epi32(*(__m128i*)(&matrix34.vec1), 0x00));	// xxxx
	    __m128 yyyy = _mm_castsi128_ps(_mm_shuffle_epi32(*(__m128i*)(&matrix34.vec1), 0x55));	// yyyy
	    __m128 zwxy = _mm_castsi128_ps(_mm_shuffle_epi32(*(__m128i*)(&matrix34.vec1), 0x8E));	// zwxy
	    __m128 wzyw = _mm_castsi128_ps(_mm_shuffle_epi32(*(__m128i*)(&matrix34.vec1), 0xDB));	// wzyw
	    __m128 zzzz = _mm_castsi128_ps(_mm_shuffle_epi32(*(__m128i*)(&matrix34.vec1), 0xAA));	// zzzz
	    __m128 yxwy = _mm_castsi128_ps(_mm_shuffle_epi32(*(__m128i*)(&matrix34.vec1), 0x71));	// yxwy
	    __m128 tmp7 = _mm_mul_ps(*(__m128*)(&matrix34.vec2), result);

	    result = _mm_add_ps(
	        _mm_add_ps(
	            _mm_add_ps(
	                _mm_mul_ps(
	                    _mm_sub_ps(
	                        _mm_mul_ps(_mm_mul_ps(xxxx, mulVec1), zwxy),
	                        _mm_mul_ps(_mm_mul_ps(yyyy, mulVec2), wzyw)),
	                    _mm_castsi128_ps(_mm_shuffle_epi32(_mm_castps_si128(tmp7), 0xAA))),
	                _mm_mul_ps(
	                    _mm_sub_ps(
	                        _mm_mul_ps(_mm_mul_ps(zzzz, mulVec2), wzyw),
	                        _mm_mul_ps(_mm_mul_ps(xxxx, mulVec0), yxwy)),
	                    _mm_castsi128_ps(_mm_shuffle_epi32(_mm_castps_si128(tmp7), 0x55)))),
	            _mm_add_ps(
	                _mm_mul_ps(
	                    _mm_sub_ps(
	                        _mm_mul_ps(_mm_mul_ps(yyyy, mulVec0), yxwy),
	                        _mm_mul_ps(_mm_mul_ps(zzzz, mulVec1), zwxy)),
	                    _mm_castsi128_ps(_mm_shuffle_epi32(_mm_castps_si128(tmp7), 0x00))),
	                tmp7)), *(__m128*)(&matrix34.vec0));


	    loop++;
	    transformIndex = games::c_phys_util::Instance().phys_read<int>((uint64_t)dependency_index_array + 0x4 * transformIndex);
	}
	return games::c_vector3(result.m128_f32[0], result.m128_f32[1], result.m128_f32[2]);
}
