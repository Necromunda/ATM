#include "dburl.h"

dbUrl::dbUrl()
{
   baseurl="http://localhost:3000";
   //baseurl="http://pv4.fiddler:3000";
}

QString dbUrl::getBaseurl() const
{
return baseurl;
}
