#ifndef __OLYM_XENGINE_MANAGEMENT_PROTOCOL_H__
#define __OLYM_XENGINE_MANAGEMENT_PROTOCOL_H__

#ifdef __cplusplus
extern "C" {
#endif

#ifndef uint8
#define uint8	unsigned char
#endif

#ifndef uint16
#define uint16	unsigned short
#endif

#ifndef uint32
#define uint32	unsigned int
#endif

//#ifndef ulong
//#define ulong	unsigned long
//#endif

#ifdef AIX
#include <sys/inttypes.h>
#else
#ifndef int8
#define int8	char
#endif

#ifndef int16
#define int16	short
#endif

#ifndef int32
#define int32	int
#endif
#endif

#ifndef uint64
#ifdef WIN32
#define uint64 unsigned __int64 
#else
#define uint64 unsigned long long
#endif
#endif

#ifndef sint64
#ifdef WIN32
#define sint64 __int64 
#else
#define sint64 long long
#endif
#endif

/*****************************VARIOUS KEY INSTALLMENT*******************************/

#define ATMEL_MAGIC_SEC_INDEX		4		//SMS IBC key request magic computation
#define ATMEL_ACK_SEC_INDEX			5		//SMS IBC ACK mac computation
#define ATMEL_MGMT_SEC_INDEX		6		//SMS IBC mgmt key computation
#define ATMEL_PBKDF_SEC_INDEX		7		//SMS pbe-used session key computation

#define PBOC_KDF_DACK_INDEX			8		//PBOC DACK KDF
#define PBOC_KDF_DAMK_INDEX			9		//PBOC DAMK KDF
#define PBOC_KDF_DPK_INDEX			10		//PBOC DPK KDF
#define PBOC_KDF_DLK_INDEX			11		//PBOC DLK KDF
#define PBOC_KDF_DTK_INDEX			12		//PBOC DTK KDF

/*****************************VARIOUS KEY INSTALLMENT*******************************/

typedef struct _xengine_alg_status{
	int32 random_status;
	int32 soft_alg_status;
	int32 dev_sm4_status;
	int32 dev_sm3_status;
	int32 dev_sm9_enc_status;
	int32 dev_sm9_sign_status;
	int32 dev_sm2_enc_status;
	int32 dev_sm2_sign_status;
	int32 card_sm2_enc_status;
	int32 card_sm2_sign_status;
	int32 usb_status;
	uint8 reserved[60];
}xengine_alg_status;

typedef struct xengine_device_cfg_{
	int32 max_key_num;
#define DEVCFG_TWOKEY_PERINDEX		0x01
#define DEVCFG_SEPERATE_SECINDEX	0x02
	uint32 device_config;
	uint8 reserved[512-8];
}xengine_device_cfg;

typedef struct{
	uint32 nVer;
	uint32 nKeyIndex;
	uint32 nOp;
#define SET_XGNINELICENSE			1	//��ͨ����LICENSE,����Ѿ����ù��ˣ��򲻿�����
#define REBURN_XGNINELICENSE		2	
#define INCREASE_XGNINELICENSE		3

	uint8  nLicenseIndex[8];
	uint32 nSeq;
	uint32 nTotalNum;
	uint32 nIncreasement;  
	uint8  ucRandom[20];
	uint8  ucMagic[20];
}XEngineLicense_t;

typedef struct{
	uint32	nVer;			//begin from 1
	uint32	nType;			//0:���������ɣ� 1:��������
	uint64	nIssueTime;
	uint64	nStartTime;		//utc time; time zone: 0;
	uint64	nDeadTime;
	uint32	nSeq;			//for update check
	uint8	ucSeqNum[8];
	uint8	ucUser[8];		//user
	uint8	ucIssuer[8];	//issuer
	uint8	ucDevId[32];	//sha1,base64,zero pad
	uint8	ucMagic[20];	//sha1,zero pad
}XEngineDevLicense_t;//112

#define	MaxDevLicenseLen	(32*1024)

typedef struct{
	uint8 bUsed;
	uint8 cAlg;
	uint8 bPub;
	uint8 bPrv;
	uint32 nBits;
}XEngineKeyInfo_t;

#define MAX_KEY_ID	192

typedef struct{
	uint8 bUsed;
	uint8 cAlg;
	uint8 bPub;
	uint8 bPrv;
	uint32 nBits;
	uint8 bKeyId[MAX_KEY_ID];
}XEngineKeyInfoEx_t;

#define	XENGINE_MGMT_PORT		9080

//#undef GM_SUCCESS
//#define GM_SUCCESS 1

#define	MKEY_PROTECT_MODE_RAW		1
#define	MKEY_PROTECT_MODE_SM2		2
#define MKEY_PROTECT_MODE_HOMM2KMS	3
#define MKEY_PROTECT_MODE_HOMM2USR	4

#define CREDENTIAL_DECRYPT	0x01
#define CREDENTIAL_SIGN		0x02
//#define CREDENTIAL_ENCRYPT	0x04
//#define CREDENTIAL_VERIFY	0x08

#define INSERT_BLOCKED_ID		1
#define REMOVE_BLOCKED_ID		2
#define LIST_BLOCKED_ID			3
#define INSERT_BLOCKED_WLDCARD	4

#define BLOCKID_OP_BITNUM		8
#define BLOCKID_OP_MASK			((0x01<<BLOCKID_OP_BITNUM)-1)
#define BLOCKID_OFFSET_MASK		(~BLOCKID_OP_MASK) //8K blocked ID

#define INSERT_ALLOWED_IP		1
#define REMOVE_ALLOWED_IP		2
#define LIST_ALLOWED_IP			3
#define INSERT_ALLOWED_WLDIP	4

#define XMSERVER_INSERT_ALLOWED_IP		5
#define XMSERVER_REMOVE_ALLOWED_IP		6
#define XMSERVER_LIST_ALLOWED_IP		7
#define XMSERVER_INSERT_ALLOWED_WLDIP	8

#define BLOCKED_IDLIST	1
#define ALLOWED_IPLIST	2
#define XMSERVER_ALLOWED_IPLIST	3




#define GET_SYSTEM_IP			1
#define SET_SYSTEM_IP			2

#define GET_SYSTEM_ROUTE		3
#define SET_SYSTEM_ROUTE		4
#define DEL_SYSTEM_ROUTE		5
#define GET_SYSTEM_XCNF			6
#define SET_SYSTEM_XCNF			7

#define GET_SYSTEM_TIME			1
#define SET_SYSTEM_TIME			2

#define ALLOWEDIP_OP_BITNUM		8
#define ALLOWEDIP_OP_MASK		((0x01<<ALLOWEDIP_OP_BITNUM)-1)
#define ALLOWEDIP_OFFSET_MASK	(~ALLOWEDIP_OP_MASK) //8K allowed IP

//#define PARAM_TYPE_IBC			0
//#define PARAM_TYPE_PKI			1

#define ALG_TIBC					0x60000000

#define KEYTYPE_IBC		0
#define KEYTYPE_RSA		1
#define KEYTYPE_KGC		2
#define KEYTYPE_SEC		3
#define KEYTYPE_ECC		4
#define KEYTYPE_TIBC	5		//SM9 identity private key with full parameter, exporting parameter from this type of key shoud be dealt differently
#define KEYTYPE_TKGC	6		//SM9 master secret key with full parameter, exporting parameter from this type of key shoud be dealt differently

#define KEYTYPE_TPKISEC	7		//Threshold secret key for SM2 
#define KEYTYPE_TIBCSEC	8		//Threshold secret key for SM9
#define KEYTYPE_TEEMMK	9		//TEEE master key
#define KEYTYPE_ECS_KGC	10
#define KEYTYPE_ECS_IBC	11
#define KEYTYPE_IBBE_KGC	12
#define KEYTYPE_IBBE_IBC	13

#define KEYTYPE_ECS_PUBKEY	14
#define KEYTYPE_OPE_SECKEY	15
#define KEYTYPE_OPEPAIR_SECKEY	16
#define KEYTYPE_OPEPAIR_PART_SECKEY	17
#define KEYTYPE_HOMM		18

#define KEYTYPE_MAX		KEYTYPE_HOMM

#define XENGINE_MGMT_SUCCESS			1
#define XENGINE_MGMT_ERR_BASE			0xFFFFF000		//-4096
#define XENGINE_MGMT_ERR_NO_MEM			(XENGINE_MGMT_ERR_BASE-1)
#define XENGINE_MGMT_ERR_ARGUMENT		(XENGINE_MGMT_ERR_BASE-2)
#define XENGINE_MGMT_ERR_OTLS_CONTEXT	(XENGINE_MGMT_ERR_BASE-3)
#define XENGINE_MGMT_ERR_OTLS_CONNECT	(XENGINE_MGMT_ERR_BASE-4)
#define XENGINE_MGMT_ERR_FRONT_THREAD   (XENGINE_MGMT_ERR_BASE-5)
#define XENGINE_MGMT_ERR_PACKET_TYPE	(XENGINE_MGMT_ERR_BASE-6)
#define XENGINE_MGMT_ERR_NO_CONNECT		(XENGINE_MGMT_ERR_BASE-7)
#define XENGINE_MGMT_ERR_NO_RESPONSE	(XENGINE_MGMT_ERR_BASE-8)
#define XENGINE_MGMT_ERR_INVALID_PKT	(XENGINE_MGMT_ERR_BASE-9)
#define XENGINE_MGMT_ERR_SEND_FAIL		(XENGINE_MGMT_ERR_BASE-10)
#define XENGINE_MGMT_ERR_INTERNAL		(XENGINE_MGMT_ERR_BASE-11)
#define XENGINE_MGMT_ERR_SECENV_FULL	(XENGINE_MGMT_ERR_BASE-12)
#define XEGNINE_MGMT_ERR_OUTPUT_TOO_LONG	(XENGINE_MGMT_ERR_BASE-13)
#define XENGINE_MGMT_ERR_OPENFILE		(XENGINE_MGMT_ERR_BASE-14)
#define XENGINE_MGMT_ERR_UNKNOWN_USER	(XENGINE_MGMT_ERR_BASE-15)//δ֪�û�
#define XENGINE_MGMT_ERR_PERMIT			(XENGINE_MGMT_ERR_BASE-16)//Ȩ�޲���
#define XENGINE_MGMT_ERR_NOT_SUPPORT	(XENGINE_MGMT_ERR_BASE-17)

#define MAX_PASSWD_LEN	64

#define SET_LICENSE			1
#define GET_LICENSE			2

#define	SET_DEV_LICENSE		(1)
#define	GET_DEV_LICENSE		(2)
#define	UPDATE_DEV_LICENSE	(3)
#define	GET_DEV_ID			(4)


typedef struct
{	
	int32 nLen;		
	uint8  pPasswd[MAX_PASSWD_LEN];
}XENGINE_MgmtPasswd_t;

typedef int32 MkeyProtectMode_e;

int32 XENGINE_MgmtCreateContext(
	int8 *pConfigFile,
	int8 *pPassFile
);

int32 XENGINE_MgmtCreateContextEx(
	int8 *pConfigFile,
	int8 *pPassFile,
	int8 *pDevPin,
	int8 *pUserName
);

int32 XENGINE_MgmtRefreshContext();

int32 XENGINE_MgmtDestroyContext();

/***********************************************************************************
* Function Name           : XENGINE_MgmtConnectKgc
* Input Parameters        :	pServerIp --- server IP address.
							wPort --- server port number.
* Output Parameters       : phEngineMgmt --- KGC management instance.
* Return value            : XENGINE_MGMT_SUCCESS when succese, otherwise, return error code.
                            
* Description             : This function is used to connect KGC server. 
* Modification            : 
************************************************************************************/
int32 XENGINE_MgmtConnect(
	int8 *pServerIp,
	uint16 wPort,
	void **phEngineMgmt
);

int32 XENGINE_MgmtConnectEx(
	int8 *pServerIp,
	uint32 wPort,
	int8 *pUser,
	int8 *pPass,
	uint8 *pParam,
	uint32 wParamLen,
	void **phEngineMgmt
);

int32 XENGINE_MgmtConnectEx2(
	int8 *pServerIp,
	uint16 wPort,
	uint32 nAlg, 
	int8 *userId,
	int8 *devId,
	void *prvKey, 
	int32 prvKeyLen,
	void *pubKey,
	int32 pubKeyLen,
	void **phEngineMgmt
);

/***********************************************************************************
* Function Name           : XENGINE_MgmtDisconnectKgc
* Input Parameters        :	hEngineMgmt --- KGC management instance.
* Output Parameters       : None.
* Return value            : XENGINE_MGMT_SUCCESS when succese, otherwise, return error code.
                            
* Description             : This function is used to disconnect the front server from KGC. 
* Modification            : 
************************************************************************************/
int32 XENGINE_MgmtDisconnect(void *hEngineMgmt);

/***********************************************************************************
* Function Name           : XENGINE_MgmtSetParam
* Input Parameters        : hEngineMgmt --- KGC management instance.
							nIndex -- parameter index on the device
							nParamType -- parameter type IBC PARAMETER, PKI CERTIFICATE
							pParamData --- pointer to the parameter data.
							nParamLen --- Parameter data length.
* Output Parameters       : None.
* Return value            : XENGINE_MGMT_SUCCESS when succese, otherwise, return error code.
                            
* Description             : This function is used to set the context parameters to KGC 
                            server. 
* Modification            : 
************************************************************************************/
int32 XENGINE_MgmtSetParam( 
	void *hEngineMgmt,
	int32 nIndex,
	uint32 nParamType,
	uint8 *pParamData, 
	int32 nParamLen
);

int32 XENGINE_MgmtSetId( 
	void *hEngineMgmt,
	int32 nIndex,
	uint32 nParamType,
	uint8 *pParamData, 
	int32 nParamLen
);

/***********************************************************************************
* Function Name           : XENGINE_MgmtSetPrvKey
* Input Parameters        : hEngineMgmt --- KGC management instance.
							nKeyIndex -- key index on the device
							nShareIndex --- secret sharing index 
							eMode --- Master key protect mode.
							pProtectKey -- the key used to protect the master key
							nProtectKeyLen -- the length of the key used to protect the master key
							nKeyType --- IBC MASTER KEY, IBC PRIVATE KEY, PKI PRIVATE KEY
							pKeyData --- Master key data.
							nKeyLen --- Master key data length.
							pPasswd --- protect password used to do loading, unloading....
							nPassLen --- protect password length.
* Output Parameters       : None.
* Return value            : XENGINE_MGMT_SUCCESS when succese, otherwise, return error code.
                            
* Description             : This function is used to set the master key data to KGC. 
* Modification            : 
************************************************************************************/
int32 XENGINE_MgmtSetPrvKey(
	void *hEngineMgmt,
	int32 nKeyIndex,
	int32 nShareIndex,
	MkeyProtectMode_e eMode,
	uint8 *pProtectKey, 
	int32 nProtectKeyLen,
	uint32 nKeyType,
	uint8 *pKeyData, 
	int32 nKeyLen,
	uint8 *pPasswd,
	int32 nPassLen
);


/***********************************************************************************
* Function Name           : XENGINE_MgmtStartServer
* Input Parameters        : hEngineMgmt --- KGC management instance.
							nIndex -- key index on the device
							pPasswd --- protect password.
							nPassLen --- protect password length.
* Output Parameters       : None.
* Return value            : XENGINE_MGMT_SUCCESS when succese, otherwise, return error code.
                            
* Description             : This function is used to start the KGC server. 
* Modification            : 
************************************************************************************/
int32 XENGINE_MgmtStartServer(
	void *hEngineMgmt,
	int32 nIndex,
	uint8 *pPasswd, 
	int32 nPassLen
);


/***********************************************************************************
* Function Name           : XENGINE_MgmtStartServer
* Input Parameters        : hEngineMgmt --- KGC management instance.
							nIndex -- key index on the device
							pPasswd --- protect password.
							nPassLen --- protect password length.
* Output Parameters       : None.
* Return value            : XENGINE_MGMT_SUCCESS when succese, otherwise, return error code.
                            
* Description             : This function is used to stop the KGC server. 
* Modification            : 
************************************************************************************/
int32 XENGINE_MgmtStopServer(
	void *hEngineMgmt,
	int32 nIndex,
	uint8 *pPasswd, 
	int32 nPassLen
);

/***********************************************************************************
* Function Name           : XENGINE_MgmtLocalBackup
* Input Parameters        : hEngineMgmt --- KGC management instance.
							nIndex -- key index on the device
							pPasswd --- protect password.
							nPassLen --- protect password length.
* Output Parameters       : None.
* Return value            : XENGINE_MGMT_SUCCESS when succese, otherwise, return error code.
                            
* Description             : This function is used to backup the KGC master key and context
                            parameters to a safe local storage. 
* Modification            : 
************************************************************************************/
int32 XENGINE_MgmtLocalBackup(
	void *hEngineMgmt,
	int32 nIndex,
	uint8 *pPasswd, 
	int32 nPassLen
);


/***********************************************************************************
* Function Name           : XENGINE_MgmtSetPasswd
* Input Parameters        : hEngineMgmt --- KGC management instance.
							nIndex -- key index on the device
							pOldPasswd --- old protect password.
							nOldPassLen --- old protect password length.
							pNewPasswd --- new protect password.
							nNewPassLen --- new protect password length.
* Output Parameters       : None.
* Return value            : XENGINE_MGMT_SUCCESS when succese, otherwise, return error code.
                            
* Description             : This function is used to change the protect password. 
* Modification            : 
************************************************************************************/
int32 XENGINE_MgmtSetPasswd(
	void *hEngineMgmt,
	int32 nIndex,
	uint8 *pOldPasswd, 
	int32 nOldPassLen,
	uint8 *pNewPasswd, 
	int32 nNewPassLen
);

int32 XENGINE_MgmtListKeyInfo(
	void *hEngineMgmt,
	XEngineKeyInfo_t *keyInf,
	uint32 *keyNum
);

int32 XENGINE_MgmtListKeyInfoEx(
	void *hEngineMgmt,
	XEngineKeyInfoEx_t *keyInf,
	uint32 *keyNum
);

int32 XENGINE_MgmtListKeyInfoEx2(
	void *hEngineMgmt,
	uint32 nStartPos,
	uint32 nStopPos,
	XEngineKeyInfoEx_t *keyInf,
	uint32 *keyNum
);

int32 XENGINE_MgmtGetServerVer(
	void *hEngineMgmt,
	uint8  *pVerInfo,
	uint32 *pnVerLen
);

/***********************************************************************************
* Function Name           : XENGINE_MgmtReadParam
* Input Parameters        : hEngineMgmt --- KGC management instance.
							nIndex -- paramter index on the device
* Output Parameters       : pnShare -- the share index
							pnType --- the key type
							pData --- Pointer to the buffer to storethe context parameters.
							pnDataLen --- return the length of context parameters;
* Return value            : XENGINE_MGMT_SUCCESS when succese, otherwise, return error code.
* Description             : This function is used to retrieve the KGC context parameter. 
* Modification            : 
************************************************************************************/
int32 XENGINE_MgmtReadParam(
	void *hEngineMgmt,
	int32 nIndex,
	uint32 *pnShare,
	uint32 *pnType,
	uint8 *pData, 
	uint32 *pnDataLen
);

int32 XENGINE_MgmtReadId(
	void *hEngineMgmt,
	int32 nIndex,
	uint8 *pData, 
	uint32 *pnDataLen
);

int32 XENGINE_MgmtReadPrvKey(
	void *hEngineMgmt,
	int32 nIndex,
	uint32 *pnShare,
	uint32 *pnType,
	uint8 *pPasswd, 
	int32 nPassLen,
	MkeyProtectMode_e eMode,
	uint8 *pProtectKey, 
	int32 nProtectKeyLen, 
	uint8 *pData, 
	uint32 *pnDataLen
);

/***********************************************************************************
* Function Name           : XENGINE_MgmtQueryStatus
* Input Parameters        : hEngineMgmt --- KGC management instance.
							nIndex -- key index on the device
							nItem --- status index, zero means to read all items. 
* Output Parameters       : pData --- Pointer to the buffer to storethe KGC status.
							pnDataLen --- return the length of status;
* Return value            : XENGINE_MGMT_SUCCESS when succese, otherwise, return error code.
* Description             : This function is used to retrieve the KGC system status. 
* Modification            : 
************************************************************************************/
int32 XENGINE_MgmtQueryStatus(
	void *hEngineMgmt,
	int32 nIndex,
	uint32 nItem,
	uint8 *pData, 
	uint32 *pnDataLen
);


/***********************************************************************************
* Function Name           : XENGINE_MgmtSetupIBCSystem
* Input Parameters        : hEngineMgmt --- KGC management instance.
						    nStartingIndex -- the index for the first piece of master secret
							domain_name -- domain name
                            serial --- domain serial
							kga --- 
							schema --- 
							ctype --- 
							psize ---
							rsize --- 
							nShare --- Share count.
							nThreshold --- threshold, currently = nShare
							nShares --- number of protect passwords.
							ppPasswdArrary --- array of passwords.
* Output Parameters       : None.
* Return value            : XENGINE_MGMT_SUCCESS when succese, otherwise, return error code.
                            
* Description             : This function is used to let KGC initialize all system parameters. 
* Modification            : 
************************************************************************************/
int32 XENGINE_MgmtSetupIBCSystem(
	void *hEngineMgmt,
	uint32 nStartingIndex,
	int8 * pDomainName,
	uint32 nSerial,
	uint32 nKga,
	uint32 nSchema,
	uint32 nCtype,
	uint32 nPsize,
	uint32 nRsize,
	uint32 nShare,
	uint32 nThreshold,
	XENGINE_MgmtPasswd_t *pPasswdArrary
);

#define KGA_SM2		1
#define KGA_RSA		2
#define KGA_SEC		3
#define KGA_ECC		4

#define KGA_TPKISEC		7
#define KGA_TIBCSEC		8
#define KGA_TEEMMK		9
#define KGA_OPE_SEC		10
#define KGA_OPEPAIR_SEC	11
#define KGA_OPEPAIR_PART_SEC	12
#define KGA_HOMM			13

#define CURVE_TYPE_SM2_P256		1
#define CURVE_TYPE_NIST_P256	2
#define CRUVE_TYPE_SECG_P256	3

int32 XENGINE_MgmtGenerateKey(
	void *hEngineMgmt,
	uint32 nStartingIndex,
	int8 * pId,
	uint32 nKga,
	uint32 nCtype,
	uint32 nPsize,
	uint32 nRsize,
	uint32 nShare,
	uint32 nThreshold,
	XENGINE_MgmtPasswd_t *pPasswdArrary
);

int32 XENGINE_MgmtGenerateOpeKey(
	void *hEngineMgmt,
	uint32 nStartingIndex,
	int8 * pId,
	uint32 nKga,
	uint32 nAlg,
	uint32 nBits,
	uint32 nTau,
	uint32 nNeg,
	uint32 nScale,
	uint32 nConf,
	uint32 nShare,
	uint32 nThreshold,
	XENGINE_MgmtPasswd_t *pPasswdArrary
);

int32 XENGINE_MgmtBlackList(
	void *hEngineMgmt,
	int32 nIndex,
	uint32 nOperation,
	uint8  *pID,
	uint32 *nIDLen,
	uint32 *nIDNum
);

int32 XENGINE_MgmtIPList(
	void *hEngineMgmt,
	int32 nIndex,
	uint32 nOperation,
	uint8  *pIP,
	uint32 *nIPLen,
	uint32 *nIPNum
);

int32 XENGINE_MgmtIPAddr(
	void *hEngineMgmt,
	int32 nIndex,
	uint32 nOperation,
	uint8  *pIPAddr,
	uint32 *nIPAddrLen
);

int32 XENGINE_MgmtTime(
	void *hEngineMgmt,
	int32 nIndex,
	uint32 nOperation,
	uint8  *pTime,
	uint32 *nTimeLen
);

int32 XENGINE_MgmtSetCredential(
	void *hEngineMgmt,
	int32 nIndex,
	uint32 nOp,
	uint8 *pPasswd, 
	int32 nPassLen
);

int32 XENGINE_MgmtSetLicense(
	void *hEngineMgmt,
	int32 nIndex,
	uint32 nOp,
	uint8 *pLicense, 
	uint32 *nLicenseLen,
	uint32 *nLicenseTNum,
	uint32 *nLicenseCNum
);

/***********************************************************************************
* Function Name           : XENGINE_SetupIBCSystem_Encap
* Input Parameters        : domain_name -- domain name
                            serial --- domain serial
							nShare --- Share count.
							nThreshold --- threshold, currently = nShare
							ctype --- 
							psize ---
							rsize --- 
							kga --- 
							schema --- 
							ipAddress --- KGC ipaddress, if more than one KGC, use '\n' separate.
							pPassword --- protect password, if nShare != 1, separated by '\n'.
 Output Parameters       :  None.
* Return value            : XENGINE_MGMT_SUCCESS when succese, otherwise, return error code.
* Description             : This function is used to initialize the KGC management front end. 
* Modification            : 
************************************************************************************/
int32 XENGINE_SetupIBCSystem_Encap(
	int8 * pDomainName,
	uint32 nSerial,
	uint32 nKga,
	uint32 nSchema,
	uint32 nCtype,
	uint32 nPsize,
	uint32 nRsize,
	uint32 nShare,
	uint32 nThreshold,
	int8 *ipAddress,	 /*separated with \n*/
	uint16 nPort,
	uint32 nStartingIndex,
	int8 *pPassword	 /*separated with \n*/
);

int32 XENGINE_SetupIBCSystem_Encap_Ex(
	int8 * pDomainName,
	uint32 nSerial,
	uint32 nKga,
	uint32 nSchema,
	uint32 nCtype,
	uint32 nPsize,
	uint32 nRsize,
	uint32 nShare,
	uint32 nThreshold,
	uint32 nSetSize,
	int8 *ipAddress,	 /*separated with \n*/
	uint16 nPort,
	uint32 nStartingIndex,
	int8 *pPassword		/*separated with \n*/
);

int32 XENGINE_GenerateKey_Encap(
	int8 *ipAddress,
	uint16 nPort,
	uint32 nStartingIndex,
	int8 * pId,
	uint32 nKga,
	uint32 nCtype,
	uint32 nPsize,
	uint32 nRsize,
	uint32 nShare,
	uint32 nThreshold,
	int8 *pPassword
);

int32 XENGINE_GenerateOpeKey_Encap(
	int8 *ipAddress,
	uint16 nPort,
	uint32 nStartingIndex,
	int8 * pId,
	uint32 nKga,
	uint32 nAlg,
	uint32 nBits,
	uint32 nTau,
	uint32 nNeg,
	uint32 nScale,
	uint32 nConf,
	uint32 nShare,
	uint32 nThreshold,
	int8 *pPassword	
);

/***********************************************************************************
* Function Name           : XENGINE_RemoteBackup_Encap
* Input Parameters        : nShareIndex --- Share index.
							ipSrcAddress --- source KGC IP address.
							ipDstAddress --- destination KGC IP address.
							nPort -- MGMT port
							nSrcIndex -- the index of the key on the source device
							nDstIndex -- the index of the key on the destination device
							nPassLen --- length of password.
							pPassword --- protected password.
 Output Parameters       :  None.
* Return value            : XENGINE_MGMT_SUCCESS when succese, otherwise, return error code.
* Description             : This function is used to backup system parameters and master key
                            from one KGC to another. 
* Modification            : 
************************************************************************************/
int32 XENGINE_RemoteBackup_Encap(
	int8 *ipSrcAddress,
	int8 *ipDstAddress,
	uint16 nPort,
	uint8 nSrcIndex,
	uint8 nDstIndex,
	MkeyProtectMode_e eMode,
	uint8 *pPassword,
	uint32 nPassLen
);

/***********************************************************************************
* Function Name           : XENGINE_LocalBackup_Encap
* Input Parameters        : ipAddress --- KGC IP address.
							nPort -- KGC port
							nIndex -- key's index
                            nPassLen --- Password Length.
							pPassword --- protected password.
 Output Parameters       :  None.
* Return value            : XENGINE_MGMT_SUCCESS when succese, otherwise, return error code.
* Description             : This function is used to initialize the KGC management front end. 
* Modification            : 
************************************************************************************/
int32 XENGINE_LocalBackup_Encap(
	int8 *ipAddress,
	uint16 nPort,
	uint32 nIndex,
	uint8 *pPassword,
	uint32 nPassLen
);

/***********************************************************************************
* Function Name           : XENGINE_StartIBCSystem_Encap
* Input Parameters        : ipAddress --- KGC IP address.
							nPort -- KGC port
							nIndex -- key's index
                            nPassLen --- Password Length.
							pPassword --- protected password.
 Output Parameters       :  None.
* Return value            : XENGINE_MGMT_SUCCESS when succese, otherwise, return error code.
* Description             : This function is used to start the KGC server. 
* Modification            : 
************************************************************************************/
int32 XENGINE_StartService_Encap(
	int8 *ipAddress,
	uint16 nPort,
	uint32 nIndex,
	uint8 *pPassword,
	uint32 nPassLen
);

/***********************************************************************************
* Function Name           : XENGINE_StopService_Encap
* Input Parameters        : ipAddress --- KGC IP address.
							nPort -- KGC port
							nIndex -- key's index
                            nPassLen --- Password Length.
							pPassword --- protected password.
 Output Parameters       :  None.
* Return value            : XENGINE_MGMT_SUCCESS when succese, otherwise, return error code.
* Description             : This function is used to start the KGC server. 
* Modification            : 
************************************************************************************/
int32 XENGINE_StopService_Encap(
	int8 *ipAddress,
	uint16 nPort,
	uint32 nIndex,
	uint8 *pPassword,
	uint32 nPassLen
);

/***********************************************************************************
* Function Name           : XENGINE_StartCipherCard_Encap
* Input Parameters        : ipAddress --- KGC IP address.
							nPort -- KGC port
							pPasswd --- Server-side password card administrator password
							nPassLen --- Server-side password card administrator password length.
* Output Parameters       : None.
* Return value            : XENGINE_MGMT_SUCCESS when succese, otherwise, return error code.
                            
* Description             : This function is used to start the KGC server. 
* Modification            : 
************************************************************************************/
int32 XENGINE_StartCipherCard_Encap(
	int8 *ipAddress,
	uint16 nPort,
	uint8 *pPasswd, 
	int32 nPassLen
);

/***********************************************************************************
* Function Name           : XENGINE_StopCipherCard_Encap
* Input Parameters        : ipAddress --- KGC IP address.
							nPort -- KGC port
							pPasswd --- Server-side password card administrator password
							nPassLen --- Server-side password card administrator password length.
* Output Parameters       : None.
* Return value            : XENGINE_MGMT_SUCCESS when succese, otherwise, return error code.
                            
* Description             : This function is used to start the KGC server. 
* Modification            : 
************************************************************************************/
int32 XENGINE_StopCipherCard_Encap(
	int8 *ipAddress,
	uint16 nPort,
	uint8 *pPasswd, 
	int32 nPassLen
);

/***********************************************************************************
* Function Name           : XENGINE_StatusCipherCard_Encap
* Input Parameters        : ipAddress --- KGC IP address.
							nPort -- KGC port
							pPasswd --- Server-side password card administrator password
							nPassLen --- Server-side password card administrator password length.
* Output Parameters       : pNStatus--- Cipher Card Startup Status.
* Return value            : XENGINE_MGMT_SUCCESS when succese, otherwise, return error code.
                            
* Description             : This function is used to start the KGC server. 
* Modification            : 
************************************************************************************/
int32 XENGINE_StatusCipherCard_Encap(
	int8 *ipAddress,
	uint16 nPort,
	uint8 *pPasswd, 
	int32 nPassLen,
	uint32 *pNStatus
);

#define FILE_OP_MAX_FILE_NAME_LEN	128
#define FILE_OP_MAX_FILE_SIZE		1*1024*1024*1024
#define FILE_OP_MAX_SEG_SIZE		4*1024
#define FILE_OP_CREATE				1
#define FILE_OP_DELETE				2
#define FILE_OP_READ				3
#define FILE_OP_WRITE				4

int32 XENGINE_SyncFileOperation(
	void *hEngineMgmt,
	uint8 *nPoolId,
	uint32 nAlg,
	uint32 uiFileLength,
	uint8 *pucBuffer,
	uint8 *pucOutData,
	uint32 *puiOutDataLen
);

#define XENGINE_GROUP_MGMT_CREATE			1
#define XENGINE_GROUP_MGMT_DEL				2
#define XENGINE_GROUP_MGMT_DEL_MEMB			3
#define XENGINE_GROUP_MGMT_REPLICATE		4

int32 XENGINE_SyncGroupMgmt(
	void *hEngineMgmt,
	uint8 *nPoolId,
	uint8 *nPoolKey,
	uint32 nOp,
	uint32 nAlg,
	uint32 uiDataLen,
	uint8 *pucData,
	uint8 *pucOutData,
	uint32 *puiOutDataLen
);

int32 XENGINE_FileOperation(
	void *hEngineMgmt,
	uint8  nOp,
	uint8 *pucFileName,
	uint32 uiNameLen,
	uint32 uiFileSize,
	uint32 uiOffset,
	uint32 uiSegLen,
	uint8  *pucData,
	uint32 *puiDataLen
);

int32 XENGINE_CreateFile_Encap(
	int8 *ipAddress,
	uint16 nPort,
	uint8 *pucFileName,
	uint32 uiNameLen,
	uint32 uiFileSize
);

int32 XENGINE_ReadFile_Encap(
	int8 *ipAddress,
	uint16 nPort,
	uint8 *pucFileName,
	uint32 uiNameLen,
	uint32 uiOffset,
	uint32 *puiFileLength,
	uint8 *pucBuffer
);

int32 XENGINE_WriteFile_Encap(
	int8 *ipAddress,
	uint16 nPort,
	uint8 *pucFileName,
	uint32 uiNameLen,
	uint32 uiOffset,
	uint32 uiFileLength,
	uint8 *pucBuffer
);

int32 XENGINE_SyncFile_Encap(
	int8 *ipAddress,
	uint16 nPort,
	uint8 *nPoolId,
	uint32 nAlg,
	uint32 uiFileLength,
	uint8 *pucBuffer,
	uint8 *pucOutData,
	uint32 *puiOutLen
);

int32 XENGINE_SyncGroupMgmt_Encap(
	int8 *ipAddress,
	uint16 nPort,
	uint8 *nPoolId,
	uint8 *nPoolKey,
	uint32 nOp,
	uint32 nAlg,
	uint32 uiDataLen,
	uint8 *pucData,
	uint8 *pucOutData,
	uint32 *puiOutDataLen
);

#define CACert_OP_MAX_FILE_NAME_LEN	128
#define CACert_OP_MAX_FILE_SIZE		512*1024
#define CACert_OP_IMPORT			(0x00000001)
#define CACert_OP_DELETE			(0x00000002)
#define CACert_OP_EXPORT			(0x00000003)
#define CACert_OP_LIST				(0x00000004)
#define CACert_OP_START				(0x00000005)
#define CACert_OP_STOP				(0x00000006)
#define CACert_OP_STATUS			(0x00000007)

#define CACrl_OP_IMPORT				(0x00000008)
#define CACrl_OP_DELETE				(0x00000009)
#define CACrl_OP_EXPORT				(0x0000000A)
#define CACrl_OP_LIST				(0x0000000B)
#define CACrl_OP_START				(0x0000000C)
#define CACrl_OP_STOP				(0x0000000D)
#define CACrl_OP_STATUS				(0x0000000E)

int32 XENGINE_MgmtCACertSet(
	void *hEngineMgmt,
	uint8 *pucFileName,
	uint32 uiNameLen,
	uint8  *pucData,
	uint32 uiDataLen
);

int32 XENGINE_MgmtCACertGet(
	void *hEngineMgmt,
	uint8 *pucFileName,
	uint32 uiNameLen,
	uint8  *pucData,
	uint32 *puiDataLen
);

int32 XENGINE_MgmtCACertDel(
	void *hEngineMgmt,
	uint8 *pucFileName,
	uint32 uiNameLen
);

int32 XENGINE_MgmtCACertEnum(
	void *hEngineMgmt,
	uint8 *pucFileNames,
	uint32 *puiNameLen
);

int32 XENGINE_CACertSet_Encap(
	int8 *ipAddress,
	uint16 nPort,
	uint8 *pucFileName,
	uint32 uiNameLen,
	uint8  *pucData,
	uint32 uiDataLen	
);

int32 XENGINE_CACertGet_Encap(
	int8 *ipAddress,
	uint16 nPort,
	uint8 *pucFileName,
	uint32 uiNameLen,
	uint8  *pucData,
	uint32 *puiDataLen
);

int32 XENGINE_CACertDel_Encap(
	int8 *ipAddress,
	uint16 nPort,
	uint8 *pucFileName,
	uint32 uiNameLen
);

int32 XENGINE_CACertEnum_Encap(
	int8 *ipAddress,
	uint16 nPort,
	uint8 *pucFileNames,
	uint32 *puiNameLen
);

int32 XENGINE_CACertStart_Encap(
	int8 *ipAddress,
	uint16 nPort,
	uint8 *pucFileName,
	uint32 uiNameLen
);

int32 XENGINE_CACertStop_Encap(
	int8 *ipAddress,
	uint16 nPort,
	uint8 *pucFileName,
	uint32 uiNameLen
);

int32 XENGINE_CACertStatus_Encap(
	int8 *ipAddress,
	uint16 nPort,
	uint8 *pucFileName,
	uint32 uiNameLen,
	uint32 *puiStatus
);

int32 XENGINE_MgmtCACrlSet(
	void *hEngineMgmt,
	uint8 *pucFileName,
	uint32 uiNameLen,
	uint8  *pucData,
	uint32 uiDataLen
);

int32 XENGINE_MgmtCACrlGet(
	void *hEngineMgmt,
	uint8 *pucFileName,
	uint32 uiNameLen,
	uint8  *pucData,
	uint32 *puiDataLen
);

int32 XENGINE_MgmtCACrlDel(
	void *hEngineMgmt,
	uint8 *pucFileName,
	uint32 uiNameLen
);

int32 XENGINE_MgmtCACrlEnum(
	void *hEngineMgmt,
	uint8 *pucFileNames,
	uint32 *puiNameLen
);

int32 XENGINE_CACrlSet_Encap(
	int8 *ipAddress,
	uint16 nPort,
	uint8 *pucFileName,
	uint32 uiNameLen,
	uint8  *pucData,
	uint32 uiDataLen	
);

int32 XENGINE_CACrlGet_Encap(
	int8 *ipAddress,
	uint16 nPort,
	uint8 *pucFileName,
	uint32 uiNameLen,
	uint8  *pucData,
	uint32 *puiDataLen
);

int32 XENGINE_CACrlDel_Encap(
	int8 *ipAddress,
	uint16 nPort,
	uint8 *pucFileName,
	uint32 uiNameLen
);

int32 XENGINE_CACrlEnum_Encap(
	int8 *ipAddress,
	uint16 nPort,
	uint8 *pucFileNames,
	uint32 *puiNameLen
);

int32 XENGINE_CACrlStart_Encap(
	int8 *ipAddress,
	uint16 nPort,
	uint8 *pucFileName,
	uint32 uiNameLen
);

int32 XENGINE_CACrlStop_Encap(
	int8 *ipAddress,
	uint16 nPort,
	uint8 *pucFileName,
	uint32 uiNameLen
);

int32 XENGINE_CACrlStatus_Encap(
	int8 *ipAddress,
	uint16 nPort,
	uint8 *pucFileName,
	uint32 uiNameLen,
	uint32 *puiStatus
);

int32 XENGINE_MgmtQueryUserList_Encap(
	int8 *ipAddress,
	uint16 nPort,
	uint8 *pUserList,
	uint32 *pBufSize
);

#define USER_FLAG_ADMIN					0x08
#define	USER_FLAG_SECURITY_MANAGER		0x04
#define USER_FLAG_NET_OPERATOR			0x02
#define USER_FLAG_KEY_OPERATOR			0x01
#define USER_FLAG_ALL			USER_FLAG_ADMIN|USER_FLAG_SECURITY_MANAGER|USER_FLAG_KEY_OPERATOR|USER_FLAG_NET_OPERATOR

int32 XENGINE_MgmtAddUser_Encap(
	int8 *ipAddress,
	uint16 nPort, 
	uint8 *pUser, 
	int8 opration, 
	uint8 * pSRP5
);

int32 XENGINE_MgmtDelUser_Encap(
	int8 *ipAddress,
	uint16 nPort,
	uint8 *pUser,
	int8 nOp
);


int32 XENGINE_MgmtQueryUser_Encap(
	int8 *ipAddress,
	uint16 nPort, 
	uint8 *pUser, 
	uint8 *pIdType
);

int32 XENGINE_DelKeySet_Encap(
	int8 *ipAddress,
	uint16 nPort,
	uint32 nIndex
);

int32 XENGINE_DeleteFile_Encap(
	int8 *ipAddress,
	uint16 nPort,
	uint8 *pucFileName,
	uint32 uiNameLen
);

/***********************************************************************************
* Function Name           : XENGINE_QueryServiceStatus_Encap
* Input Parameters        : ipAddress --- KGC IP address.
							nPort -- KGC port
							nIndex -- key's index
							nQueryItem --- Query item.
							ipAddress --- KGC IP address.
							pLen --- buffer length and return status buffer length.
							pBuf --- buffer for store the status.
 Output Parameters       :  None.
* Return value            : XENGINE_MGMT_SUCCESS when succese, otherwise, return error code.
* Description             : This function is used to query the KGC server status. 
* Modification            : 
************************************************************************************/

int32 XENGINE_QueryServiceStatus_Encap (
	int8 *ipAddress,
	uint16 nPort,
	uint32 nIndex,
	uint32 nQueryItem,
	uint8 *pBuf,
	uint32 *pLen
);

/***********************************************************************************
* Function Name           : XENGINE_ChangePrvKeyPassword_Encap
* Input Parameters        : ipAddress --- KGC IP address.
							nPort -- KGC port
							nIndex -- key's index
							pOldPasswd --- old protect password.
							nOldPassLen --- old protect password length.
							pNewPasswd --- new protect password.
							nNewPassLen --- new protect password length.
* Output Parameters       : None.
* Return value            : XENGINE_MGMT_SUCCESS when succese, otherwise, return error code.
                            
* Description             : This function is used to change the protect password. 
* Modification            : 
************************************************************************************/
int32 XENGINE_ChangePrvKeyPassword_Encap(
	int8 *ipAddress,
	uint16 nPort,
	uint32 nIndex,
	uint8 *pOldPasswd, 
	int32 nOldPassLen,
	uint8 *pNewPasswd, 
	int32 nNewPassLen
);

/***********************************************************************************
* Function Name           : XENGINE_ReadIBCParameter_Encap
* Input Parameters        : ipAddress --- KGC IP address.
							nPort -- KGC port
							nIndex -- key's index
* Output Parameters       : pnType --- the type of the parameter
							pData --- Pointer to the buffer to storethe KGC context parameters.
							pnDataLen --- return the length of context parameters;
* Return value            : XENGINE_MGMT_SUCCESS when succese, otherwise, return error code.
* Description             : This function is used to retrieve the KGC context parameter. 
* Modification            : 
************************************************************************************/
int32 XENGINE_ReadParameter_Encap(
	int8 *ipAddress,
	uint16 nPort,
	uint32 nIndex,
	uint32 *pnType,
	uint8 *pData, 
	uint32 *pnDataLen
);

int32 XENGINE_ReadId_Encap(
	int8 *ipAddress,
	uint16 nPort,
	uint32 nIndex,
	uint8 *pData, 
	uint32 *pnDataLen
);

int32 XENGINE_ReadCurve_Encap(
	int8 *ipAddress,
	uint16 nPort,
	uint32 nIndex,
	uint8 *pData, 
	uint32 *pnDataLen
);

int32 XENGINE_ReadPrvKey_Encap(
	int8 *ipAddress,
	uint16 nPort,
	int32 nIndex,
	uint32 *pnShare,
	uint32 *pnType,
	uint8 *pPasswd, 
	int32 nPassLen,
	MkeyProtectMode_e eMode,
	uint8 *pProtectKey, 
	int32 nProtectKeyLen, 
	uint8 *pData, 
	uint32 *pnDataLen
);

/***********************************************************************************
* Function Name           : XENGINE_SetParameter_Encap
* Input Parameters        : ipAddress --- KGC IP address.
							nPort -- KGC port
							nIndex -- parameter index on the device
							nParamType -- parameter type IBC PARAMETER, PKI CERTIFICATE
							pParamData --- pointer to the parameter data.
							nParamLen --- Parameter data length.
* Output Parameters       : None.
* Return value            : XENGINE_MGMT_SUCCESS when succese, otherwise, return error code.
                            
* Description             : This function is used to set the context parameters to KGC 
                            server. 
* Modification            : 
************************************************************************************/
int32 XENGINE_SetParameter_Encap( 
	int8 *ipAddress,
	uint16 nPort,
	int32 nIndex,
	uint32 nParamType,
	uint8 *pParamData, 
	int32 nParamLen
);

int32 XENGINE_SetParameter_Encap_Ex( 
	int8 *ipAddress,
	uint16 nPort,
	int32 nIndex,
	MkeyProtectMode_e eMode,
	uint8 *pProtectKey, 
	uint32 nProtectKeyLen,
	uint32 nParamType,
	uint8 *pParamData, 
	int32 nParamLen
);

int32 XENGINE_SetId_Encap( 
	int8 *ipAddress,
	uint16 nPort,
	int32 nIndex,
	uint32 nParamType,
	uint8 *pParamData, 
	int32 nParamLen
);

int32 XENGINE_SetCurve_Encap( 
	int8 *ipAddress,
	uint16 nPort,
	int32 nIndex,
	uint32 nParamType,
	uint8 *pParamData, 
	int32 nParamLen
);

int32 XENGINE_GetServerVer_Encap(
	int8 *ipAddress,
	uint16 nPort,
	uint8  *pVerInfo,
	uint32 *pnVerLen
);

int32 XENGINE_ManageBlackList_Encap(
	int8 *ipAddress,
	uint16 nPort,
	int32 nIndex,
	uint32 nOperation,
	uint8  *pID,
	uint32 *nIDLen,
	uint32 *nIDNum
);

int32 XENGINE_ManageIPList_Encap(
	int8 *ipAddress,
	uint16 nPort,
	int32 nIndex,
	uint32 nOperation,
	uint8  *pIP,
	uint32 *nIPLen,
	uint32 *nIPNum
);

int32 XENGINE_ManageIPAddr_Encap(
	int8 *ipAddress,
	uint16 nPort,
	int32 nIndex,
	uint32 nOperation,
	uint8  *pIPAddr,
	uint32 *nIPAddrLen
);

int32 XENGINE_ManageTime_Encap(
	int8 *ipAddress,
	uint16 nPort,
	int32 nIndex,
	uint32 nOperation,
	uint8  *pTime,
	uint32 *nTimeLen
);

int32 XENGINE_SetPrvKey_Encap(
	int8 *ipAddress,
	uint16 nPort,
	int32 nIndex,
	uint32 nShare,
	MkeyProtectMode_e eMode,
	uint8 *pProtectKey, 
	int32 nProtectKeyLen, 
	uint32 nKeyType,
	uint8 *pKeyData, 
	int32 nKeyLen,
	uint8 *pPasswd,
	int32 nPassLen
);

int32 XENGINE_SetCredential_Encap(
	int8 *ipAddress,
	uint16 nPort,
	int32 nIndex,
	uint32 nOp,
	uint8 *pPasswd, 
	int32 nPassLen
);

int32 XENGINE_ChangeCredential_Encap(
	int8 *ipAddress,
	uint16 nPort,
	int32 nIndex,
	uint8 *pOldPasswd,
	int32 nOldPassLen,
	uint8 *pNewPasswd, 
	int32 nNewPassLen
);

int32 XENGINE_SetLicense_Encap(
	int8 *ipAddress,
	uint16 nPort,
	int32 nIndex,
	uint32 nOp,
	uint8 *pLicense, 
	uint32 *nLicenseLen,
	uint32 *nLicenseTNum,
	uint32 *nLicenseCNum
);

int32 XENGINE_SetDevLicense_Encap(
	int8 *ipAddress,
	uint16 nPort,
	uint32 nOp,
	uint8 *pLicense, 
	uint32 *nLicenseLen
);

int32 XENGINE_ListKeyInfo_Encap(
	int8 *ipAddress,
	uint16 nPort,
	XEngineKeyInfo_t *keyInf,
	uint32 *keyNum
);

int32 XENGINE_ListKeyInfoEx_Encap(
	int8 *ipAddress,
	uint16 nPort,
	XEngineKeyInfoEx_t *keyInf,
	uint32 *keyNum
);

int32 XENGINE_ListKeyInfoEx2_Encap(
	int8 *ipAddress,
	uint16 nPort,
	uint32 nStartPos,
	uint32 nStopPos,
	XEngineKeyInfoEx_t *keyInf,
	uint32 *keyNum
);

#if 0
int32 XENGINE_SetupIBCCipher_Encap(
	int8 *kgcIpAddress,			//KGC ip address
	uint16 nKgcMgmtPort,		//KGC mgmt port
	uint16 nKgcServicePort,		//KGC service port 
	int32 nKgcIndex,			//The index of the master key on the KGC device
	uint8 *pKgcCredential,		//The KGC master access credential 
	int32 nKgcCredentialLen,	//The length of the KGC master access credential
	int8 *paramFile,			//The IBC parameter file
	uint8 *pucRawId,			//The key identity
	uint32 uiRawIdLen,			//The lenght of the identity
	int8 *cipherIpAddress,		//XEngine device IP
	uint16 nCipherMgmtPort,		//XEngine device management port
	int32 nCipherIndex,			//The index of the cipher key on the XEngine device
	uint8 *pCredential,			//The cipher key access credential
	int32 nCredentialLen		//The length of the cipher key access credential
);

int32 XENGINE_SetupIBCCipher_EncapEx(
	int8 *kgcIpAddress,			//KGC ip address
	uint16 nKgcMgmtPort,		//KGC mgmt port
	uint16 nKgcServicePort,		//KGC service port 
	int32 nKgcIndex,			//The index of the master key on the KGC device
	uint8 *pKgcCredential,		//The KGC master access credential 
	int32 nKgcCredentialLen,	//The length of the KGC master access credential
	int8 *paramFile,			//The IBC parameter file
	uint8 *pucRawId,			//The key identity
	uint32 uiRawIdLen,			//The lenght of the identity
	int8 *cipherIpAddress,		//XEngine device IP
	uint16 nCipherMgmtPort,		//XEngine device management port
	int32 nCipherIndex,			//The index of the cipher key on the XEngine device
	uint8 *pCredential,			//The cipher key access credential
	int32 nCredentialLen,		//The length of the cipher key access credential
	uint8 *pPass,				//protecting password
	int32 nPassLen				//protecting password length
);
#endif

int32 XENGINE_RemoteBackup_EncapEx(
	int8 *ipSrcAddress,
	int8 *ipDstAddress,
	uint16 nPort,
	uint8 nSrcIndex,
	uint8 nDstIndex,
	MkeyProtectMode_e eMode,
	uint8 *pPassword,
	uint32 nPassLen,
	uint32 nConversion
);

int32 XENGINE_RemoteBackup_EncapEx2(
	int8 *ipSrcAddress,
	int8 *ipDstAddress,
	uint16 nPort,
	uint32 nSrcIndex,
	uint32 nDstIndex,
	MkeyProtectMode_e eMode,
	uint8 *pPassword,
	uint32 nPassLen,
	uint32 bConversion,
	uint32 nConversion
);

int32 XENGINEInitSecurityEnv();

int32 XENGINESetSecurityEnv(
	int8 *sIp, 
	uint32 wport, 
	uint32 uAlg, 
	int8 *userId,
	int8 *devId,
	void *prvKey, 
	int32 prvKeyLen,
	void *pubKey,
	int32 pubKeyLen
);

void *XENGINEFindSecurityEvn(
	int8 *pServerIp,
	uint32 wPort										   
);

int32 XENGINEDelSecurityEnv(
	int8 *pServerIp,
	uint32 wPort										   
);

int32 XENGINEClearSecurityEnv();

int32 XENGINE_MgmtSetSvrPassword(
	void *hEngineMgmt,
	int32 nIndex,
	uint32 nOp,
	uint8 *pPasswd, 
	int32 nPassLen
);

int32 XENGINE_MgmtSetSRP5Password(
	void *hEngineMgmt,
	uint32 nOp,
	uint8 *pPasswd, 
	int32 nPassLen
);

int32 XENGINE_MgmtSetSRP5PasswordEx(
	void *hEngineMgmt,
	uint32 nOp,
	uint8 *pUser,
	int32 nUserLen,
	uint8 *pPasswd, 
	int32 nPassLen
);

int32 XENGINE_SetSvrPassword_Encap(
	int8 *ipAddress,
	uint16 nPort,
	int32 nIndex,
	uint32 nOp,
	uint8 *pPasswd, 
	int32 nPassLen
);

int32 XENGINE_SetSRP5Password_Encap(
	int8 *ipAddress,
	uint16 nPort,
	uint32 nOp,
	uint8 *pPasswd, 
	int32 nPassLen
);

int32 XENGINE_SetSRP5Password_EncapEx(
	int8 *ipAddress,
	uint16 nPort,
	uint32 nOp,
	uint8 *pUser,
	int32 nUserLen,
	uint8 *pPasswd, 
	int32 nPassLen
);

int32 XENGINE_SetSvrCredential_Encap(
	int8 *ipAddress,
	uint16 nPort,
	int32 nIndex,
	uint32 nShare,
	uint8 *pPasswd, 
	int32 nPassLen
);

int32 XENGINE_SetSvrCredentialEx_Encap(
	int8 *ipAddress,
	uint16 nPort,
	int32 nSuitIndex,
	uint32 nShare,
	uint32 nRedun,
	int32 nKgcIndex,
	int32 nParam,
	uint32 nOption,
	uint8 *pPasswd, 
	int32 nPassLen,
	uint8 *pUser,
	int32 nUserLen,
	uint8 *pServer,
	int32 nServerLen,
	int32 nServerPort,
	uint32 nTotlRedun,
	uint32 nTotlShare
);

int32 XENGINE_MgmtSetSvrCredential(
	void *hEngineMgmt,
	int32 nIndex,
	uint32 nShare,
	uint8 *pPasswd, 
	int32 nPassLen
);

int32 XENGINE_MgmtGetCredential(
	void *hEngineMgmt,
	int32 nIndex,
	uint32 nOp,
	uint8 *pPasswd, 
	uint32 *nPassLen
);

#define SET_BINDING_DEVICE(a)	(a | 0x4000)

int32 XENGINE_MgmtSetSvrCredentialEx(
	void *hEngineMgmt,
	int32 nSuitIndex,
	uint32 nShare,
	uint32 nRedun,
	uint32 nKgcIndex,
	int32 nParam,
	uint32 nOption,
	uint8 *pPasswd, 
	int32 nPassLen,
	uint8 *pUser,
	int32 nUserLen,
	uint8 *pServer,
	int32 nServerLen,
	int32 nPort,
	uint32 nTotlRedun,
	uint32 nTotlShare
);

#define GET_SERVER_ACCESS_INFO	1

int32 XENGINE_MgmtSvrAccessInfo(
	void *hEngineMgmt,
	int32  nIndex,
	uint32 nOperation,
	uint8  *pInfo,
	uint32 *nInfoLen
);

int32 XENGINE_ManageSvrAccessInfo_Encap(
	int8 *ipAddress,
	uint16 nPort,
	int32  nIndex,
	uint32 nOperation,
	uint8  *pInfo,
	uint32 *nInfoLen
);

#define GET_XCONFIG_INFO		1
#define SET_XCONFIG_ITEM		2
#define SET_XCONFIG_ITEM_EXT	3

int32 XENGINE_MgmtSvrXconfigInfo(
	void *hEngineMgmt,
	int32  nIndex,
	uint32 nOperation,
	uint8  *pInfo,
	uint32 *nInfoLen
);

int32 XENGINE_ManageSvrXconfigInfo_Encap(
	int8 *ipAddress,
	uint16 nPort,
	int32  nIndex,
	uint32 nOperation,
	uint8  *pInfo,
	uint32 *nInfoLen
);

#define START_XCIPHER		1
#define STOP_XCIPHER		2
#define RESTART_XCIPHER		3
#define SHUTDOWN_SYSTEM		4
#define RESTART_SYSTEM		5
#define RESTART_KFK			6
#define RESTART_XMSERVER	7
#define RELOAD_KGC			512

int32 XENGINE_MgmtServiceOp(
	void *hEngineMgmt,
	int32 nOp
);

int32 XENGINE_MgmtServiceOp_Encap(
	int8 *ipAddress,
	uint16 nPort,
	int32 nOp
);

int32 XENGINE_MgmtGetFileSegment(
	void *hEngineMgmt,
	uint32 nFileType,
	sint64 nOffset,
	uint8  *pFileSeg,
	uint32 *pnSegLen
);

#define XENGINE_FILE_LOG		0
#define XMSERVER_FILE_LOG		1
int32 XENGINE_GetFileSegment_Encap(
	int8 *ipAddress,
	uint16 nPort,
	uint32 nFileType,
	sint64  nOffset,
	uint8  *pFileSeg,
	uint32 *pnSegLen
);

int32 XENGINE_MgmtDeviceConfig(
	void *hEngineMgmt,
	uint8 *pData, 
	uint32 *pnDataLen
);

int32 XENGINE_DeviceConfig_Encap(
	int8 *ipAddress,
	uint16 nPort,
	uint8 *pData, 
	uint32 *pnDataLen
);

#define SOFT_CHECK_ALG		0x01
#define CHECK_RANDOM		0x02
#define UKEY_CHECK_SM4		0x04
#define UKEY_CHECK_SM3		0x08
#define UKEY_CHECK_SM9		0x10
#define UKEY_CHECK_SM2		0x20
#define CARD_CHECK_SM2		0x40
#define CARD_CHECK_SM3		0x80
#define CARD_CHECK_SM4		0x100

int32 XENGINE_MgmtHealthCheck(
	void *hEngineMgmt,
	uint32 nItem,
	uint8 *pData, 
	uint32 *pnDataLen
);

int32 XENGINE_HealthCheck_Encap(
	int8 *ipAddress,
	uint16 nPort,
	uint32 nItem,
	uint8 *pData, 
	uint32 *pnDataLen
);


#define XENGINE_MGMT_HARDWARE_TYPE		1
#define XENGINE_MGMT_NTLS_LOG_LEVEL		2
#define XENGINE_MGMT_NTLS_LOG_FILE		3
#define XENGINE_MGMT_NTLS_DEM_ALG		4
#define XENGINE_MGMT_NTLS_SOCKS_PORT	5
int32 XENGINE_MgmtSetConfig(
	uint32 nConfigAttr,
	void   *pConfigValue,
	uint32 nConfigLen
);

int32 XENGINE_SetLMKKey_Encap(
	int8 *ipAddress,
	uint16 nPort,
	MkeyProtectMode_e eMode,
	uint8 *pProtectKey, 
	int32 nProtectKeyLen,
	uint8 *pKeyData, 
	int32 nKeyLen
);

int32 XENGINE_ReadLMKKey_Encap(
	int8 *ipAddress,
	uint16 nPort,
	MkeyProtectMode_e eMode,
	uint8 *pProtectKey, 
	int32 nProtectKeyLen, 
	uint8 *pData, 
	uint32 *pnDataLen
);

extern int xmclient_use_hardware;

void XENGINE_XM_Version(
	int8 *ver
);

#ifdef __cplusplus
}
#endif

#endif


