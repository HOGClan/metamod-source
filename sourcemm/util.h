/* ======== SourceMM ========
 * Copyright (C) 2004-2007 Metamod:Source Development Team
 * No warranties of any kind
 *
 * License: zlib/libpng
 *
 * Author(s): David "BAILOPAN" Anderson
 * ============================
 */

#ifndef _INCLUDE_UTIL_H
#define _INCLUDE_UTIL_H

#include <stdarg.h>

/**
 * @brief Utility functions
 * @file util.h
 */

/**
 * @brief Returns a pointer to the extension in a file name.
 */
const char *UTIL_GetExtension(const char *file);

/**
 * @brief Removes C-style comments from string.
 */
void UTIL_TrimComments(char *buffer);

/**
 * @brief Removes whitespace characters from left side of string.
 */
void UTIL_TrimLeft(char *buffer);

/**
 * @brief Removes whitespace characters from right side of string.
 */
void UTIL_TrimRight(char *buffer);

/**
 * @brief Breaks a string at the first space until it reaches a non-space.
 */
void UTIL_KeySplit(const char *str, char *buf1, size_t len1, char *buf2, size_t len2);

/**
 * @brief Compares two file paths.
 */
bool UTIL_PathCmp(const char *path1, const char *path2);

/**
 * @brief Same as snprintf except that it ensures the string buffer is null terminated.
 */
size_t UTIL_Format(char *buffer, size_t maxlength, const char *fmt, ...);

/**
 * @brief Same as vsnprintf except that it ensures the string buffer is null terminated.
 */
inline size_t UTIL_FormatArgs(char *buffer, size_t maxlength, const char *fmt, va_list params)
{
	size_t len = vsnprintf(buffer, maxlength, fmt, params);

	if (len >= maxlength)
	{
		len = maxlength - 1;
		buffer[len] = '\0';
	}

	return len;
}

#endif //_INCLUDE_UTIL_H
