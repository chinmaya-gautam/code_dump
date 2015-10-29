#q4.awk

BEGIN {
  print "\nemployee\t\tbasic\t\tda\t\t\hra\t\tgross"
  print "_____________________________________________________________________________________________"
}

{
  da=0.15*$6
  hra=0.1*$6
  gross=$6+da+hra
 
  fbasic+=$6
  fda+=da
  fhra+=hra
  fgross+=gross

  print $2,"\t\t",$6,"\t\t",da,"\t\t",hra,"\t\t",gross
  
}
END{
  print "_____________________________________________________________________________________________"
  print "\n\nfirm expenditures\n\n"
  print "basic\t\tda\t\t\hra\t\tgross"
  print "_____________________________________________________________________________________________"
  print fbasic,"\t\t",fda,"\t\t",fhra,"\t\t",fgross
}