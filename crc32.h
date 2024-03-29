/* SPDX-License-Identifier: GPL-2.0 */

#ifndef __CRC32_H
#define __CRC32_H

/**
 * CRC32 checksum computation.
 *
 * WARNING: this implementation is optimized using precomputed lookup tables.
 * The tables are meant to be computed during runtime and it is user's
 * responsibility to call crc32_initialize() function manually. Alternatively,
 * ehen #CRC32_AUTOINIT macro is defined, initialization is run automatically.
 *
 * On success, functions crc32_fd() and crc32_file() return a positive number
 * representing computed checksum. On error, a negative error code is returned.
 * Error codes correspond to errno(3).
 */

#define CRC32_AUTOINIT

uint32_t crc32(FILE *file);

#endif /* __CRC32_H */