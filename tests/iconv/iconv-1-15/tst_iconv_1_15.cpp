#include <QtTest>

#include <stdlib.h>
#include <stdio.h>

#include "iconv.h"

class iconv_1_15 : public QObject
{
  Q_OBJECT

private slots:
  void test_iconv();
};

void iconv_1_15::test_iconv()
{
  // conversion descriptor from iso-8859-1 to utf8
  iconv_t cd = iconv_open("UTF-8", "ISO-8859-1");

  if (cd == reinterpret_cast<iconv_t>(-1))
    QFAIL("Failed iconv_open");

  QString s = "æøå";
  char *expected = s.toUtf8().data();
  char *inbuf = s.toLatin1().data();

  // utf-8 'æøå'
  QCOMPARE(expected, "\u00E6\u00F8\u00E5");

  // iso-8859-1 'æøå'
  QCOMPARE(inbuf, "\xE6\xF8\xE5");

  size_t inbytesleft = 4;
  size_t outbytesleft = 7;
  char *outbuf = static_cast<char *>(calloc(outbytesleft, sizeof(char)));
  char *actual = outbuf;

  size_t ret = iconv(cd, &inbuf, &inbytesleft, &outbuf, &outbytesleft);

  if(ret == static_cast<size_t>(-1)) {
    perror("iconv");
  }
  else
  {
    QCOMPARE(actual, expected);
  }

  iconv_close(cd);

  free(inbuf);
  free(outbuf);
}

QTEST_APPLESS_MAIN(iconv_1_15)

#include "tst_iconv_1_15.moc"
