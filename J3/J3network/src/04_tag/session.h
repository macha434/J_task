/*********************************************/
/*       File name:  session.h               */
/*    Project name:  socket/tag              */
/*      Month/Year:  Jan/2003                */
/*          Author:  Shuichi YUKITA          */
/*********************************************/

extern void  session_init(int soc,
                          char mc, int mx, int my,
                          char pc, int px, int py);

extern void  session_loop();
