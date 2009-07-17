#!/bin/bash

if test "x$1" == "xclean"; then
  rm -rf autom4te.cache
  rm -f  configure
  rm -f  cycle.hin
  rm -f  cycle.hin~
  echo 'Clean'
  exit 0
fi

echo 'Producing mkcycle from configure.ac'

autoreconf --install --force --verbose
autoreconf --install --force --verbose

n=`cat configure | wc -l`
m=`expr $n - 12`

head -n 12 configure          >  mkcycle
echo 'cat >cycle.hin <<\_EOF' >> mkcycle
cat cycle.hin                 >> mkcycle
echo '_EOF'                   >> mkcycle
tail -n $m configure          >> mkcycle
echo 'rm -f cycle.hin'        >> mkcycle
echo 'rm -f config.log'       >> mkcycle
echo 'rm -f config.status'    >> mkcycle

chmod 755 mkcycle

echo 'DONE'
