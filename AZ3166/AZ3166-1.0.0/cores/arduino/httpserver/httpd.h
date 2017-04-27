#ifndef _HTTPD_H_
#define _HTTPD_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include "helper.h"
#include "http_parse.h"
#include "httpd_handle.h"
#include "httpd_utility.h"
#include "httpd_wsgi.h"

/** @brief Initialize the httpd
 *
 *  @note  This function must be called before any of the other API functions.  If any
 *  of the initialization steps fail, the function will fail.
 *
 *  @return WM_SUCCESS if successful
 *  @return -WM_FAIL otherwise
 */
int httpd_init(void);

/** @brief  Shutdown the httpd
 *
 *  @note  This function is the opposite of httpd_init().  It cleans up any
 *  resources used by the httpd.  If the httpd thread is running (i.e.,
 *  httpd_stop has not been called), it will be halted.
 *
 *  @return WM_SUCCESS   :if successful
 *  @return -WM_FAIL     :otherwise
 *
 */
int httpd_shutdown(void);

/** @brief   Start the httpd
 *
 *  @note    Upon WM_SUCCESS, the user can expect that the server is running and
 *  ready to receive connections.  httpd_stop() should be called to stop the
 *  server.  A return value of -WM_FAIL generally indicates that the thread
 *  has already been started.
 *
 *  @return   WM_SUCCESS      :if successful
 *  @return   WM_FAIL         :otherwise
 */
int httpd_start(void);

/** @brief    Stop the httpd
  *
  * @note     This function is the opposite of httpd_start().  It stops the httpd.  If
  *  WM_SUCCESS is returned, the server has been stopped and will no longer
  *  accept connections.  -WM_FAIL is returned if the httpd is uninitialized, or
  *  if an internal error occurs (which is not expected).  Note that this
  *  function forces the httpd thread to stop and closes any open sockets. If
  *  a handler is being executed during this time, it will be terminated.
  *
  * @return   WM_SUCCESS      : if successful
  * @return   WM_FAIL         : otherwise
  */
int httpd_stop(void);

/** @brief    Check if httpd is running
 *
 *  @return   0              : if httpd is not running
 *  @return   non-zero       : if it is running
 */
int httpd_is_running(void);

bool httpd_is_https_active( void );

char *get_httpd_auth( void );

#ifdef __cplusplus
}
#endif

#endif