#q2.awk
BEGIN{
    print "shows inbuilt functions"
}
{
  print toupper(substr($0, 4,7))


}
END {}