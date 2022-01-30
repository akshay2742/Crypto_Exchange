#include <stdio.h>
#define max_yr 9999
#define min_yr 1800

int isleap(int y) {
   if((y % 4 == 0) && (y % 100 != 0) && (y % 400 == 0))
      return 1;
   else
      return 0;
}

int datevalid(int d, int m, int y) {
   if(y < min_yr || y > max_yr)
      return 0;
   if(m < 1 || m > 12)
      return 0;
   if(d < 1 || d > 31)
      return 0;
      //Now we will check date according to month
   if( m == 2 ) {
      if(isleap(y)) {
         if(d <= 29)
            return 1;
         else
            return 0;
         }
      }
      //April, June, September and November are with 30 days
      if ( m == 4 || m == 6 || m == 9 || m == 11 )
         if(d <= 30)
            return 1;
         else
            return 0;
            return 1;
   }