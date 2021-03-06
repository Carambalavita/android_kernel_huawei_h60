


/*****************************************************************************
  1 头文件包含
*****************************************************************************/
#include "VcCtx.h"



#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


/*****************************************************************************
    协议栈打印打点方式下的.C文件宏定义
*****************************************************************************/
/*lint -e(767)*/
#define    THIS_FILE_ID        PS_FILE_ID_APP_VC_CTX_C


/*****************************************************************************
  2 全局变量定义
*****************************************************************************/

/* VC CTX,用于保存VC上下文 */
APP_VC_STATE_MGMT_STRU                    g_stAppVcCtx;


/*****************************************************************************
   3 函数实现
*****************************************************************************/


APP_VC_STATE_MGMT_STRU*  APP_VC_GetCtx( VOS_VOID )
{
    return &(g_stAppVcCtx);
}


APP_VC_MS_CFG_INFO_STRU* APP_VC_GetCustomCfgInfo( VOS_VOID )
{
    return &(APP_VC_GetCtx()->stMsCfgInfo);
}


#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif



