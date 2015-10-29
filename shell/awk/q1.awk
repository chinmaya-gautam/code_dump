#q1.awk

BEGIN {
print  "\nemployee no. Name" 
print  "======================"
}

{
  if($3 == "am"){
    print $1," \t|\t", $2
  }

}
END {
print "========================"
}