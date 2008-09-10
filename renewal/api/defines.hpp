#ifndef _DEFINES_H_
# define _DEFINES_H_

#ifdef __linux 
# ifndef SOCKET
typedef int SOCKET;
# endif
#else
# ifdef __BSD_VISIBLE
#  ifndef SOCKET
typedef int SOCKET;
#  endif
# else
#  include <Winsock2.h>
# endif
#endif

namespace ZenZiAPI
{
  const int hookPointsNumber = 8;
  const int hookPositionNumber = 5;

    enum hookPosition		/**< callbacks postions at a Hook Point*/
      {
	VERY_FIRST,		/**< only one very first position */
	FIRST,			/**< many first position */
	MIDDLE,			/**< many middle position*/
	LAST,			/**< many last position */
	VERY_LAST		/**< onlu one very last position */
      };

    enum hookPoint		/**< possible Hook Points */
      {
	NEW_CLIENT,		/**< On client accept  */
	DATA_IN,		/**< before BNF parsing */
	PARSED,			/**< after BNF parsing */
	FILESYSTEM,		/**< when a filesystem ressource is fetch */
	DATA_OUT,		/**< before sending */
	DEL_CLIENT,		/**< When closing client */
	READ,			/**< read hook point */
	WRITE,			/**< write hook point */
      };
};

#endif
