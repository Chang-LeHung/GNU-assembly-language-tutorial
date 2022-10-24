
dirs=
for dir in $(ls)
do
  if [ -d $dir ]
  then
    dirs="$dirs $dir"
  fi
done

echo $dirs