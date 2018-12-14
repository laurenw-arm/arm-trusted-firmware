/*
 * Copyright (c) 2018, Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef SPCI_SVC_H
#define SPCI_SVC_H

#include <lib/smccc.h>
#include <lib/utils_def.h>

/* SPCI_VERSION helpers */

#define SPCI_VERSION_MAJOR		U(0)
#define SPCI_VERSION_MAJOR_SHIFT	16
#define SPCI_VERSION_MAJOR_MASK		U(0x7FFF)
#define SPCI_VERSION_MINOR		U(1)
#define SPCI_VERSION_MINOR_SHIFT	0
#define SPCI_VERSION_MINOR_MASK		U(0xFFFF)
#define SPCI_VERSION_FORM(major, minor)	((((major) & SPCI_VERSION_MAJOR_MASK)  \
						<< SPCI_VERSION_MAJOR_SHIFT) | \
					((minor) & SPCI_VERSION_MINOR_MASK))
#define SPCI_VERSION_COMPILED		SPCI_VERSION_FORM(SPCI_VERSION_MAJOR, \
							  SPCI_VERSION_MINOR)

/* Definitions to build the complete SMC ID */

#define SPCI_FID_MISC_FLAG		(U(0) << 27)
#define SPCI_FID_MISC_SHIFT		U(20)
#define SPCI_FID_MISC_MASK		U(0x7F)

#define SPCI_FID_TUN_FLAG		(U(1) << 27)
#define SPCI_FID_TUN_SHIFT		U(24)
#define SPCI_FID_TUN_MASK		U(0x7)

#define SPCI_SMC(spci_fid)	((FUNCID_NAMESPACE_SPCI << FUNCID_NAMESPACE_SHIFT) | \
				 (U(1) << 31) | (spci_fid))
#define SPCI_MISC_32(misc_fid)	((SMC_32 << FUNCID_CC_SHIFT) |	\
				 SPCI_FID_MISC_FLAG |		\
				 SPCI_SMC((misc_fid) << SPCI_FID_MISC_SHIFT))
#define SPCI_MISC_64(misc_fid)	((SMC_64 << FUNCID_CC_SHIFT) |	\
				 SPCI_FID_MISC_FLAG |		\
				 SPCI_SMC((misc_fid) << SPCI_FID_MISC_SHIFT))
#define SPCI_TUN_32(tun_fid)	((SMC_32 << FUNCID_CC_SHIFT) |	\
				 SPCI_FID_TUN_FLAG |		\
				 SPCI_SMC((tun_fid) << SPCI_FID_TUN_SHIFT))
#define SPCI_TUN_64(tun_fid)	((SMC_64 << FUNCID_CC_SHIFT) |	\
				 SPCI_FID_TUN_FLAG |		\
				 SPCI_SMC((tun_fid) << SPCI_FID_TUN_SHIFT))

/* SPCI miscellaneous functions */

#define SPCI_FID_VERSION			U(0x0)
#define SPCI_FID_SERVICE_HANDLE_OPEN		U(0x2)
#define SPCI_FID_SERVICE_HANDLE_CLOSE		U(0x3)
#define SPCI_FID_SERVICE_MEM_REGISTER		U(0x4)
#define SPCI_FID_SERVICE_MEM_UNREGISTER		U(0x5)
#define SPCI_FID_SERVICE_MEM_PUBLISH		U(0x6)
#define SPCI_FID_SERVICE_REQUEST_BLOCKING	U(0x7)
#define SPCI_FID_SERVICE_REQUEST_START		U(0x8)
#define SPCI_FID_SERVICE_GET_RESPONSE		U(0x9)
#define SPCI_FID_SERVICE_RESET_CLIENT_STATE	U(0xA)

/* SPCI tunneling functions */

#define SPCI_FID_SERVICE_TUN_REQUEST_START	U(0x0)
#define SPCI_FID_SERVICE_REQUEST_RESUME		U(0x1)
#define SPCI_FID_SERVICE_TUN_REQUEST_BLOCKING	U(0x2)

/* Complete SMC IDs and associated values */

#define SPCI_VERSION				SPCI_MISC_32(SPCI_FID_VERSION)

#define SPCI_SERVICE_HANDLE_OPEN		SPCI_MISC_32(SPCI_FID_SERVICE_HANDLE_OPEN)
#define SPCI_SERVICE_HANDLE_OPEN_NOTIFY_BIT	U(1)

#define SPCI_SERVICE_HANDLE_CLOSE		SPCI_MISC_32(SPCI_FID_SERVICE_HANDLE_CLOSE)

#define SPCI_SERVICE_MEM_REGISTER_AARCH32	SPCI_MISC_32(SPCI_FID_SERVICE_MEM_REGISTER)
#define SPCI_SERVICE_MEM_REGISTER_AARCH64	SPCI_MISC_64(SPCI_FID_SERVICE_MEM_REGISTER)

#define SPCI_SERVICE_MEM_UNREGISTER_AARCH32	SPCI_MISC_32(SPCI_FID_SERVICE_MEM_UNREGISTER)
#define SPCI_SERVICE_MEM_UNREGISTER_AARCH64	SPCI_MISC_64(SPCI_FID_SERVICE_MEM_UNREGISTER)

#define SPCI_SERVICE_MEM_PUBLISH_AARCH32	SPCI_MISC_32(SPCI_FID_SERVICE_MEM_PUBLISH)
#define SPCI_SERVICE_MEM_PUBLISH_AARCH64	SPCI_MISC_64(SPCI_FID_SERVICE_MEM_PUBLISH)

#define SPCI_SERVICE_REQUEST_BLOCKING_AARCH32	SPCI_MISC_32(SPCI_FID_SERVICE_REQUEST_BLOCKING)
#define SPCI_SERVICE_REQUEST_BLOCKING_AARCH64	SPCI_MISC_64(SPCI_FID_SERVICE_REQUEST_BLOCKING)

#define SPCI_SERVICE_REQUEST_START_AARCH32	SPCI_MISC_32(SPCI_FID_SERVICE_REQUEST_START)
#define SPCI_SERVICE_REQUEST_START_AARCH64	SPCI_MISC_64(SPCI_FID_SERVICE_REQUEST_START)

#define SPCI_SERVICE_GET_RESPONSE_AARCH32	SPCI_MISC_32(SPCI_FID_SERVICE_GET_RESPONSE)
#define SPCI_SERVICE_GET_RESPONSE_AARCH64	SPCI_MISC_64(SPCI_FID_SERVICE_GET_RESPONSE)

#define SPCI_SERVICE_RESET_CLIENT_STATE_AARCH32	SPCI_MISC_32(SPCI_FID_SERVICE_RESET_CLIENT_STATE)
#define SPCI_SERVICE_RESET_CLIENT_STATE_AARCH64	SPCI_MISC_64(SPCI_FID_SERVICE_RESET_CLIENT_STATE)

#define SPCI_SERVICE_TUN_REQUEST_START_AARCH32	SPCI_TUN_32(SPCI_FID_SERVICE_TUN_REQUEST_START)
#define SPCI_SERVICE_TUN_REQUEST_START_AARCH64	SPCI_TUN_64(SPCI_FID_SERVICE_TUN_REQUEST_START)

#define SPCI_SERVICE_REQUEST_RESUME_AARCH32	SPCI_TUN_32(SPCI_FID_SERVICE_REQUEST_RESUME)
#define SPCI_SERVICE_REQUEST_RESUME_AARCH64	SPCI_TUN_64(SPCI_FID_SERVICE_REQUEST_RESUME)

#define SPCI_SERVICE_TUN_REQUEST_BLOCKING_AARCH32 SPCI_TUN_32(SPCI_FID_SERVICE_TUN_REQUEST_BLOCKING)
#define SPCI_SERVICE_TUN_REQUEST_BLOCKING_AARCH64 SPCI_TUN_64(SPCI_FID_SERVICE_TUN_REQUEST_BLOCKING)

/* SPCI error codes. */

#define SPCI_SUCCESS		 0
#define SPCI_NOT_SUPPORTED	-1
#define SPCI_INVALID_PARAMETER	-2
#define SPCI_NO_MEMORY		-3
#define SPCI_BUSY		-4
#define SPCI_QUEUED		-5
#define SPCI_DENIED		-6
#define SPCI_NOT_PRESENT	-7

#endif /* SPCI_SVC_H */
