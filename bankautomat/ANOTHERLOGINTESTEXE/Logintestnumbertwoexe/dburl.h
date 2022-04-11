#ifndef DBURL_H
#define DBURL_H

#include <qstring.h>



class dbUrl
{
public:
    dbUrl();

    QString getBaseurl() const;

private:
    QString baseurl;
};

#endif // DBURL_H
