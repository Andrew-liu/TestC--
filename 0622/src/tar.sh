#!/bin/sh

cd ./
tarFile = "shell.tar.gz"
tar czvf $tarFile *.sh

cd ../
mkdir backup
code = $?
if[ $code -eq 0 ]
then
echo $code #状态码
cd -
cp shell.tar.gz ../backup/
else
	cd -
	rm -rf ../backup/*
	cp $tarFile ../backup
fi
