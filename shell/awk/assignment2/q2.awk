#q2.awk
BEGIN {
print "enter word to be searched"
getline word < "-"
count=0
linecount=0
}

{
    counted=0
    for( i=1; i<=NF; i++){ 
      if($i ==	word){
	if(counted == 0){
	  counted =1
	  linecount++
	}
	count++
      }
    }
   
}
END{
print word," occurs ",count,"no. of times in the file\n"
print word," occurs in",linecount,"no. of lines in the file"
}