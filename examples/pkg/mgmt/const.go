// THE AUTOGENERATED LICENSE. ALL THE RIGHTS ARE RESERVED BY ROBOTS.

// WARNING: This file has automatically been generated on Tue, 30 Jul 2024 12:57:57 CST.
// Code generated by https://git.io/c-for-go. DO NOT EDIT.

package mgmt

/*
#cgo CFLAGS: -I.
#include "xengine_mgmt_op.h"
#include <stdlib.h>
#include "cgo_helpers.h"
*/
import "C"

const (
	// ATMEL_MAGIC_SEC_INDEX as defined in mgmt/xengine_mgmt_op.h:58
	ATMEL_MAGIC_SEC_INDEX = 4
	// ATMEL_ACK_SEC_INDEX as defined in mgmt/xengine_mgmt_op.h:59
	ATMEL_ACK_SEC_INDEX = 5
	// ATMEL_MGMT_SEC_INDEX as defined in mgmt/xengine_mgmt_op.h:60
	ATMEL_MGMT_SEC_INDEX = 6
	// ATMEL_PBKDF_SEC_INDEX as defined in mgmt/xengine_mgmt_op.h:61
	ATMEL_PBKDF_SEC_INDEX = 7
	// PBOC_KDF_DACK_INDEX as defined in mgmt/xengine_mgmt_op.h:63
	PBOC_KDF_DACK_INDEX = 8
	// PBOC_KDF_DAMK_INDEX as defined in mgmt/xengine_mgmt_op.h:64
	PBOC_KDF_DAMK_INDEX = 9
	// PBOC_KDF_DPK_INDEX as defined in mgmt/xengine_mgmt_op.h:65
	PBOC_KDF_DPK_INDEX = 10
	// PBOC_KDF_DLK_INDEX as defined in mgmt/xengine_mgmt_op.h:66
	PBOC_KDF_DLK_INDEX = 11
	// PBOC_KDF_DTK_INDEX as defined in mgmt/xengine_mgmt_op.h:67
	PBOC_KDF_DTK_INDEX = 12
	// SET_XGNINELICENSE as defined in mgmt/xengine_mgmt_op.h:98
	SET_XGNINELICENSE = 1
	// MAX_KEY_ID as defined in mgmt/xengine_mgmt_op.h:134
	MAX_KEY_ID = 192
	// XENGINE_MGMT_PORT as defined in mgmt/xengine_mgmt_op.h:145
	XENGINE_MGMT_PORT = 9080
	// MKEY_PROTECT_MODE_RAW as defined in mgmt/xengine_mgmt_op.h:150
	MKEY_PROTECT_MODE_RAW = 1
	// MKEY_PROTECT_MODE_SM2 as defined in mgmt/xengine_mgmt_op.h:151
	MKEY_PROTECT_MODE_SM2 = 2
	// MKEY_PROTECT_MODE_HOMM2KMS as defined in mgmt/xengine_mgmt_op.h:152
	MKEY_PROTECT_MODE_HOMM2KMS = 3
	// MKEY_PROTECT_MODE_HOMM2USR as defined in mgmt/xengine_mgmt_op.h:153
	MKEY_PROTECT_MODE_HOMM2USR = 4
	// CREDENTIAL_DECRYPT as defined in mgmt/xengine_mgmt_op.h:155
	CREDENTIAL_DECRYPT = 0x01
	// CREDENTIAL_SIGN as defined in mgmt/xengine_mgmt_op.h:156
	CREDENTIAL_SIGN = 0x02
	// INSERT_BLOCKED_ID as defined in mgmt/xengine_mgmt_op.h:160
	INSERT_BLOCKED_ID = 1
	// REMOVE_BLOCKED_ID as defined in mgmt/xengine_mgmt_op.h:161
	REMOVE_BLOCKED_ID = 2
	// LIST_BLOCKED_ID as defined in mgmt/xengine_mgmt_op.h:162
	LIST_BLOCKED_ID = 3
	// INSERT_BLOCKED_WLDCARD as defined in mgmt/xengine_mgmt_op.h:163
	INSERT_BLOCKED_WLDCARD = 4
	// BLOCKID_OP_BITNUM as defined in mgmt/xengine_mgmt_op.h:165
	BLOCKID_OP_BITNUM = 8
	// BLOCKID_OP_MASK as defined in mgmt/xengine_mgmt_op.h:166
	BLOCKID_OP_MASK = ((0x01 << BLOCKID_OP_BITNUM) - 1)
	// BLOCKID_OFFSET_MASK as defined in mgmt/xengine_mgmt_op.h:167
	BLOCKID_OFFSET_MASK = (^BLOCKID_OP_MASK)
	// INSERT_ALLOWED_IP as defined in mgmt/xengine_mgmt_op.h:169
	INSERT_ALLOWED_IP = 1
	// REMOVE_ALLOWED_IP as defined in mgmt/xengine_mgmt_op.h:170
	REMOVE_ALLOWED_IP = 2
	// LIST_ALLOWED_IP as defined in mgmt/xengine_mgmt_op.h:171
	LIST_ALLOWED_IP = 3
	// INSERT_ALLOWED_WLDIP as defined in mgmt/xengine_mgmt_op.h:172
	INSERT_ALLOWED_WLDIP = 4
	// XMSERVER_INSERT_ALLOWED_IP as defined in mgmt/xengine_mgmt_op.h:174
	XMSERVER_INSERT_ALLOWED_IP = 5
	// XMSERVER_REMOVE_ALLOWED_IP as defined in mgmt/xengine_mgmt_op.h:175
	XMSERVER_REMOVE_ALLOWED_IP = 6
	// XMSERVER_LIST_ALLOWED_IP as defined in mgmt/xengine_mgmt_op.h:176
	XMSERVER_LIST_ALLOWED_IP = 7
	// XMSERVER_INSERT_ALLOWED_WLDIP as defined in mgmt/xengine_mgmt_op.h:177
	XMSERVER_INSERT_ALLOWED_WLDIP = 8
	// BLOCKED_IDLIST as defined in mgmt/xengine_mgmt_op.h:179
	BLOCKED_IDLIST = 1
	// ALLOWED_IPLIST as defined in mgmt/xengine_mgmt_op.h:180
	ALLOWED_IPLIST = 2
	// XMSERVER_ALLOWED_IPLIST as defined in mgmt/xengine_mgmt_op.h:181
	XMSERVER_ALLOWED_IPLIST = 3
	// GET_SYSTEM_IP as defined in mgmt/xengine_mgmt_op.h:186
	GET_SYSTEM_IP = 1
	// SET_SYSTEM_IP as defined in mgmt/xengine_mgmt_op.h:187
	SET_SYSTEM_IP = 2
	// GET_SYSTEM_ROUTE as defined in mgmt/xengine_mgmt_op.h:189
	GET_SYSTEM_ROUTE = 3
	// SET_SYSTEM_ROUTE as defined in mgmt/xengine_mgmt_op.h:190
	SET_SYSTEM_ROUTE = 4
	// GET_SYSTEM_XCNF as defined in mgmt/xengine_mgmt_op.h:192
	GET_SYSTEM_XCNF = 6
	// SET_SYSTEM_XCNF as defined in mgmt/xengine_mgmt_op.h:193
	SET_SYSTEM_XCNF = 7
	// GET_SYSTEM_TIME as defined in mgmt/xengine_mgmt_op.h:195
	GET_SYSTEM_TIME = 1
	// SET_SYSTEM_TIME as defined in mgmt/xengine_mgmt_op.h:196
	SET_SYSTEM_TIME = 2
	// ALLOWEDIP_OP_BITNUM as defined in mgmt/xengine_mgmt_op.h:198
	ALLOWEDIP_OP_BITNUM = 8
	// ALLOWEDIP_OP_MASK as defined in mgmt/xengine_mgmt_op.h:199
	ALLOWEDIP_OP_MASK = ((0x01 << ALLOWEDIP_OP_BITNUM) - 1)
	// ALLOWEDIP_OFFSET_MASK as defined in mgmt/xengine_mgmt_op.h:200
	ALLOWEDIP_OFFSET_MASK = (^ALLOWEDIP_OP_MASK)
	// ALG_TIBC as defined in mgmt/xengine_mgmt_op.h:205
	ALG_TIBC = 0x60000000
	// KEYTYPE_IBC as defined in mgmt/xengine_mgmt_op.h:207
	KEYTYPE_IBC = 0
	// KEYTYPE_RSA as defined in mgmt/xengine_mgmt_op.h:208
	KEYTYPE_RSA = 1
	// KEYTYPE_KGC as defined in mgmt/xengine_mgmt_op.h:209
	KEYTYPE_KGC = 2
	// KEYTYPE_SEC as defined in mgmt/xengine_mgmt_op.h:210
	KEYTYPE_SEC = 3
	// KEYTYPE_ECC as defined in mgmt/xengine_mgmt_op.h:211
	KEYTYPE_ECC = 4
	// KEYTYPE_TIBC as defined in mgmt/xengine_mgmt_op.h:212
	KEYTYPE_TIBC = 5
	// KEYTYPE_TKGC as defined in mgmt/xengine_mgmt_op.h:213
	KEYTYPE_TKGC = 6
	// KEYTYPE_TPKISEC as defined in mgmt/xengine_mgmt_op.h:215
	KEYTYPE_TPKISEC = 7
	// KEYTYPE_TIBCSEC as defined in mgmt/xengine_mgmt_op.h:216
	KEYTYPE_TIBCSEC = 8
	// KEYTYPE_TEEMMK as defined in mgmt/xengine_mgmt_op.h:217
	KEYTYPE_TEEMMK = 9
	// KEYTYPE_ECS_KGC as defined in mgmt/xengine_mgmt_op.h:218
	KEYTYPE_ECS_KGC = 10
	// KEYTYPE_ECS_IBC as defined in mgmt/xengine_mgmt_op.h:219
	KEYTYPE_ECS_IBC = 11
	// KEYTYPE_IBBE_KGC as defined in mgmt/xengine_mgmt_op.h:220
	KEYTYPE_IBBE_KGC = 12
	// KEYTYPE_IBBE_IBC as defined in mgmt/xengine_mgmt_op.h:221
	KEYTYPE_IBBE_IBC = 13
	// KEYTYPE_ECS_PUBKEY as defined in mgmt/xengine_mgmt_op.h:223
	KEYTYPE_ECS_PUBKEY = 14
	// KEYTYPE_OPE_SECKEY as defined in mgmt/xengine_mgmt_op.h:224
	KEYTYPE_OPE_SECKEY = 15
	// KEYTYPE_OPEPAIR_SECKEY as defined in mgmt/xengine_mgmt_op.h:225
	KEYTYPE_OPEPAIR_SECKEY = 16
	// KEYTYPE_OPEPAIR_PART_SECKEY as defined in mgmt/xengine_mgmt_op.h:226
	KEYTYPE_OPEPAIR_PART_SECKEY = 17
	// KEYTYPE_HOMM as defined in mgmt/xengine_mgmt_op.h:227
	KEYTYPE_HOMM = 18
	// KEYTYPE_MAX as defined in mgmt/xengine_mgmt_op.h:229
	KEYTYPE_MAX = KEYTYPE_HOMM
	// XENGINE_MGMT_SUCCESS as defined in mgmt/xengine_mgmt_op.h:231
	XENGINE_MGMT_SUCCESS = 1
	// XENGINE_MGMT_ERR_BASE as defined in mgmt/xengine_mgmt_op.h:232
	XENGINE_MGMT_ERR_BASE = 0xFFFFF000
	// XENGINE_MGMT_ERR_NO_MEM as defined in mgmt/xengine_mgmt_op.h:233
	XENGINE_MGMT_ERR_NO_MEM = (XENGINE_MGMT_ERR_BASE - 1)
	// XENGINE_MGMT_ERR_ARGUMENT as defined in mgmt/xengine_mgmt_op.h:234
	XENGINE_MGMT_ERR_ARGUMENT = (XENGINE_MGMT_ERR_BASE - 2)
	// XENGINE_MGMT_ERR_OTLS_CONTEXT as defined in mgmt/xengine_mgmt_op.h:235
	XENGINE_MGMT_ERR_OTLS_CONTEXT = (XENGINE_MGMT_ERR_BASE - 3)
	// XENGINE_MGMT_ERR_OTLS_CONNECT as defined in mgmt/xengine_mgmt_op.h:236
	XENGINE_MGMT_ERR_OTLS_CONNECT = (XENGINE_MGMT_ERR_BASE - 4)
	// XENGINE_MGMT_ERR_FRONT_THREAD as defined in mgmt/xengine_mgmt_op.h:237
	XENGINE_MGMT_ERR_FRONT_THREAD = (XENGINE_MGMT_ERR_BASE - 5)
	// XENGINE_MGMT_ERR_PACKET_TYPE as defined in mgmt/xengine_mgmt_op.h:238
	XENGINE_MGMT_ERR_PACKET_TYPE = (XENGINE_MGMT_ERR_BASE - 6)
	// XENGINE_MGMT_ERR_NO_CONNECT as defined in mgmt/xengine_mgmt_op.h:239
	XENGINE_MGMT_ERR_NO_CONNECT = (XENGINE_MGMT_ERR_BASE - 7)
	// XENGINE_MGMT_ERR_NO_RESPONSE as defined in mgmt/xengine_mgmt_op.h:240
	XENGINE_MGMT_ERR_NO_RESPONSE = (XENGINE_MGMT_ERR_BASE - 8)
	// XENGINE_MGMT_ERR_INVALID_PKT as defined in mgmt/xengine_mgmt_op.h:241
	XENGINE_MGMT_ERR_INVALID_PKT = (XENGINE_MGMT_ERR_BASE - 9)
	// XENGINE_MGMT_ERR_SEND_FAIL as defined in mgmt/xengine_mgmt_op.h:242
	XENGINE_MGMT_ERR_SEND_FAIL = (XENGINE_MGMT_ERR_BASE - 10)
	// XENGINE_MGMT_ERR_INTERNAL as defined in mgmt/xengine_mgmt_op.h:243
	XENGINE_MGMT_ERR_INTERNAL = (XENGINE_MGMT_ERR_BASE - 11)
	// XENGINE_MGMT_ERR_SECENV_FULL as defined in mgmt/xengine_mgmt_op.h:244
	XENGINE_MGMT_ERR_SECENV_FULL = (XENGINE_MGMT_ERR_BASE - 12)
	// XEGNINE_MGMT_ERR_OUTPUT_TOO_LONG as defined in mgmt/xengine_mgmt_op.h:245
	XEGNINE_MGMT_ERR_OUTPUT_TOO_LONG = (XENGINE_MGMT_ERR_BASE - 13)
	// XENGINE_MGMT_ERR_OPENFILE as defined in mgmt/xengine_mgmt_op.h:246
	XENGINE_MGMT_ERR_OPENFILE = (XENGINE_MGMT_ERR_BASE - 14)
	// XENGINE_MGMT_ERR_UNKNOWN_USER as defined in mgmt/xengine_mgmt_op.h:247
	XENGINE_MGMT_ERR_UNKNOWN_USER = (XENGINE_MGMT_ERR_BASE - 15)
	// XENGINE_MGMT_ERR_PERMIT as defined in mgmt/xengine_mgmt_op.h:248
	XENGINE_MGMT_ERR_PERMIT = (XENGINE_MGMT_ERR_BASE - 16)
	// XENGINE_MGMT_ERR_NOT_SUPPORT as defined in mgmt/xengine_mgmt_op.h:249
	XENGINE_MGMT_ERR_NOT_SUPPORT = (XENGINE_MGMT_ERR_BASE - 17)
	// MAX_PASSWD_LEN as defined in mgmt/xengine_mgmt_op.h:251
	MAX_PASSWD_LEN = 64
	// SET_LICENSE as defined in mgmt/xengine_mgmt_op.h:253
	SET_LICENSE = 1
	// GET_LICENSE as defined in mgmt/xengine_mgmt_op.h:254
	GET_LICENSE = 2
	// SET_DEV_LICENSE as defined in mgmt/xengine_mgmt_op.h:256
	SET_DEV_LICENSE = (1)
	// GET_DEV_LICENSE as defined in mgmt/xengine_mgmt_op.h:257
	GET_DEV_LICENSE = (2)
	// UPDATE_DEV_LICENSE as defined in mgmt/xengine_mgmt_op.h:258
	UPDATE_DEV_LICENSE = (3)
	// GET_DEV_ID as defined in mgmt/xengine_mgmt_op.h:259
	GET_DEV_ID = (4)
	// KGA_SM2 as defined in mgmt/xengine_mgmt_op.h:607
	KGA_SM2 = 1
	// KGA_RSA as defined in mgmt/xengine_mgmt_op.h:608
	KGA_RSA = 2
	// KGA_SEC as defined in mgmt/xengine_mgmt_op.h:609
	KGA_SEC = 3
	// KGA_ECC as defined in mgmt/xengine_mgmt_op.h:610
	KGA_ECC = 4
	// KGA_TPKISEC as defined in mgmt/xengine_mgmt_op.h:612
	KGA_TPKISEC = 7
	// KGA_TIBCSEC as defined in mgmt/xengine_mgmt_op.h:613
	KGA_TIBCSEC = 8
	// KGA_TEEMMK as defined in mgmt/xengine_mgmt_op.h:614
	KGA_TEEMMK = 9
	// KGA_OPE_SEC as defined in mgmt/xengine_mgmt_op.h:615
	KGA_OPE_SEC = 10
	// KGA_OPEPAIR_SEC as defined in mgmt/xengine_mgmt_op.h:616
	KGA_OPEPAIR_SEC = 11
	// KGA_OPEPAIR_PART_SEC as defined in mgmt/xengine_mgmt_op.h:617
	KGA_OPEPAIR_PART_SEC = 12
	// KGA_HOMM as defined in mgmt/xengine_mgmt_op.h:618
	KGA_HOMM = 13
	// CURVE_TYPE_SM2_P256 as defined in mgmt/xengine_mgmt_op.h:620
	CURVE_TYPE_SM2_P256 = 1
	// CURVE_TYPE_NIST_P256 as defined in mgmt/xengine_mgmt_op.h:621
	CURVE_TYPE_NIST_P256 = 2
	// XENGINE_GROUP_MGMT_CREATE as defined in mgmt/xengine_mgmt_op.h:950
	XENGINE_GROUP_MGMT_CREATE = 1
	// XENGINE_GROUP_MGMT_DEL as defined in mgmt/xengine_mgmt_op.h:951
	XENGINE_GROUP_MGMT_DEL = 2
	// XENGINE_GROUP_MGMT_DEL_MEMB as defined in mgmt/xengine_mgmt_op.h:952
	XENGINE_GROUP_MGMT_DEL_MEMB = 3
	// XENGINE_GROUP_MGMT_REPLICATE as defined in mgmt/xengine_mgmt_op.h:953
	XENGINE_GROUP_MGMT_REPLICATE = 4
	// CACert_OP_MAX_FILE_NAME_LEN as defined in mgmt/xengine_mgmt_op.h:1031
	CACert_OP_MAX_FILE_NAME_LEN = 128
	// CACert_OP_MAX_FILE_SIZE as defined in mgmt/xengine_mgmt_op.h:1032
	CACert_OP_MAX_FILE_SIZE = 512 * 1024
	// CACert_OP_IMPORT as defined in mgmt/xengine_mgmt_op.h:1033
	CACert_OP_IMPORT = (0x00000001)
	// CACert_OP_DELETE as defined in mgmt/xengine_mgmt_op.h:1034
	CACert_OP_DELETE = (0x00000002)
	// CACert_OP_EXPORT as defined in mgmt/xengine_mgmt_op.h:1035
	CACert_OP_EXPORT = (0x00000003)
	// CACert_OP_LIST as defined in mgmt/xengine_mgmt_op.h:1036
	CACert_OP_LIST = (0x00000004)
	// CACert_OP_START as defined in mgmt/xengine_mgmt_op.h:1037
	CACert_OP_START = (0x00000005)
	// CACert_OP_STOP as defined in mgmt/xengine_mgmt_op.h:1038
	CACert_OP_STOP = (0x00000006)
	// CACert_OP_STATUS as defined in mgmt/xengine_mgmt_op.h:1039
	CACert_OP_STATUS = (0x00000007)
	// CACrl_OP_IMPORT as defined in mgmt/xengine_mgmt_op.h:1041
	CACrl_OP_IMPORT = (0x00000008)
	// CACrl_OP_DELETE as defined in mgmt/xengine_mgmt_op.h:1042
	CACrl_OP_DELETE = (0x00000009)
	// CACrl_OP_EXPORT as defined in mgmt/xengine_mgmt_op.h:1043
	CACrl_OP_EXPORT = (0x0000000A)
	// CACrl_OP_LIST as defined in mgmt/xengine_mgmt_op.h:1044
	CACrl_OP_LIST = (0x0000000B)
	// CACrl_OP_START as defined in mgmt/xengine_mgmt_op.h:1045
	CACrl_OP_START = (0x0000000C)
	// CACrl_OP_STOP as defined in mgmt/xengine_mgmt_op.h:1046
	CACrl_OP_STOP = (0x0000000D)
	// CACrl_OP_STATUS as defined in mgmt/xengine_mgmt_op.h:1047
	CACrl_OP_STATUS = (0x0000000E)
	// USER_FLAG_ADMIN as defined in mgmt/xengine_mgmt_op.h:1220
	USER_FLAG_ADMIN = 0x08
	// USER_FLAG_SECURITY_MANAGER as defined in mgmt/xengine_mgmt_op.h:1221
	USER_FLAG_SECURITY_MANAGER = 0x04
	// USER_FLAG_NET_OPERATOR as defined in mgmt/xengine_mgmt_op.h:1222
	USER_FLAG_NET_OPERATOR = 0x02
	// USER_FLAG_KEY_OPERATOR as defined in mgmt/xengine_mgmt_op.h:1223
	USER_FLAG_KEY_OPERATOR = 0x01
	// USER_FLAG_ALL as defined in mgmt/xengine_mgmt_op.h:1224
	USER_FLAG_ALL = USER_FLAG_ADMIN | USER_FLAG_SECURITY_MANAGER | USER_FLAG_KEY_OPERATOR | USER_FLAG_NET_OPERATOR
	// GET_SERVER_ACCESS_INFO as defined in mgmt/xengine_mgmt_op.h:1744
	GET_SERVER_ACCESS_INFO = 1
	// GET_XCONFIG_INFO as defined in mgmt/xengine_mgmt_op.h:1763
	GET_XCONFIG_INFO = 1
	// SET_XCONFIG_ITEM as defined in mgmt/xengine_mgmt_op.h:1764
	SET_XCONFIG_ITEM = 2
	// SET_XCONFIG_ITEM_EXT as defined in mgmt/xengine_mgmt_op.h:1765
	SET_XCONFIG_ITEM_EXT = 3
	// START_XCIPHER as defined in mgmt/xengine_mgmt_op.h:1784
	START_XCIPHER = 1
	// STOP_XCIPHER as defined in mgmt/xengine_mgmt_op.h:1785
	STOP_XCIPHER = 2
	// RESTART_XCIPHER as defined in mgmt/xengine_mgmt_op.h:1786
	RESTART_XCIPHER = 3
	// SHUTDOWN_SYSTEM as defined in mgmt/xengine_mgmt_op.h:1787
	SHUTDOWN_SYSTEM = 4
	// RESTART_SYSTEM as defined in mgmt/xengine_mgmt_op.h:1788
	RESTART_SYSTEM = 5
	// RESTART_KFK as defined in mgmt/xengine_mgmt_op.h:1789
	RESTART_KFK = 6
	// RESTART_XMSERVER as defined in mgmt/xengine_mgmt_op.h:1790
	RESTART_XMSERVER = 7
	// RELOAD_KGC as defined in mgmt/xengine_mgmt_op.h:1791
	RELOAD_KGC = 512
	// XENGINE_FILE_LOG as defined in mgmt/xengine_mgmt_op.h:1812
	XENGINE_FILE_LOG = 0
	// XMSERVER_FILE_LOG as defined in mgmt/xengine_mgmt_op.h:1813
	XMSERVER_FILE_LOG = 1
	// SOFT_CHECK_ALG as defined in mgmt/xengine_mgmt_op.h:1836
	SOFT_CHECK_ALG = 0x01
	// CHECK_RANDOM as defined in mgmt/xengine_mgmt_op.h:1837
	CHECK_RANDOM = 0x02
	// UKEY_CHECK_SM4 as defined in mgmt/xengine_mgmt_op.h:1838
	UKEY_CHECK_SM4 = 0x04
	// UKEY_CHECK_SM3 as defined in mgmt/xengine_mgmt_op.h:1839
	UKEY_CHECK_SM3 = 0x08
	// UKEY_CHECK_SM9 as defined in mgmt/xengine_mgmt_op.h:1840
	UKEY_CHECK_SM9 = 0x10
	// UKEY_CHECK_SM2 as defined in mgmt/xengine_mgmt_op.h:1841
	UKEY_CHECK_SM2 = 0x20
	// CARD_CHECK_SM2 as defined in mgmt/xengine_mgmt_op.h:1842
	CARD_CHECK_SM2 = 0x40
	// CARD_CHECK_SM3 as defined in mgmt/xengine_mgmt_op.h:1843
	CARD_CHECK_SM3 = 0x80
	// CARD_CHECK_SM4 as defined in mgmt/xengine_mgmt_op.h:1844
	CARD_CHECK_SM4 = 0x100
	// XENGINE_MGMT_HARDWARE_TYPE as defined in mgmt/xengine_mgmt_op.h:1862
	XENGINE_MGMT_HARDWARE_TYPE = 1
	// XENGINE_MGMT_NTLS_LOG_LEVEL as defined in mgmt/xengine_mgmt_op.h:1863
	XENGINE_MGMT_NTLS_LOG_LEVEL = 2
	// XENGINE_MGMT_NTLS_LOG_FILE as defined in mgmt/xengine_mgmt_op.h:1864
	XENGINE_MGMT_NTLS_LOG_FILE = 3
	// XENGINE_MGMT_NTLS_DEM_ALG as defined in mgmt/xengine_mgmt_op.h:1865
	XENGINE_MGMT_NTLS_DEM_ALG = 4
	// XENGINE_MGMT_NTLS_SOCKS_PORT as defined in mgmt/xengine_mgmt_op.h:1866
	XENGINE_MGMT_NTLS_SOCKS_PORT = 5
)
