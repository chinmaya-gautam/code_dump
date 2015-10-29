#q3.awk
BEGIN{
count = 0;
total=0;
}
{
  if ($6 > 50000){
    print $0
  }
count+=1;
total+=$6;
}

END{
print "average salary: ",total/count 
}