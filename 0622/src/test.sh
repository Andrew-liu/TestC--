#!/bin/sh

echo $PWD

for ((i=0;i<10;i++))
do
	echo $i
done

for i in $(seq 10) #获取10以内的整数用空格分开
do
	echo $i
done
if  [ $i -eq 10 ] #-eq = -lt <  -gt >
then
	echo "loop for endding"
fi
if [ $i -lt 11 ]
then
	echo "i < 11"
fi
if [ $i -gt 11 ]
then 
	echo "i > 11"
else
	echo "i < 11"
fi

while [[ $i -gt 5 ]];do
	echo $i;
	((i--));
done;
function start
{
	touch start.sh
	chmod 744 start.sh
	echo "test" > start.sh
	cat /dev/null > start.sh
	echo "#!/bin/sh" >> start.sh
	echo "sleep 10" >> start.sh
	./start.sh & # 去后台运行
	wait
	echo "start 10 exec endding..."
}
case $1 in
	start | begin)
	start ;;
	stop | end)
	echo "end ........";;
	*)
	echo "Ignoe...." ;; 
esac
