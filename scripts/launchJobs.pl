use Env;



open(USERCONFIG,$ARGV[0]);
while(<USERCONFIG>)
{
  chomp;
  s/#.*//;                # no comments
  s/^\s+//;               # no leading white
  s/\s+$//;               # no trailing white
  my($var,$value) = split(/\s*=\s*/, $_, 2);
  $User_Preferences{$var} = $value;
}

$CRYSTALCfg = $User_Preferences{"CRYSTALCfg"};
$GPSMac     = $User_Preferences{"GPSMac"};
$OUTPUTDir  = $User_Preferences{"OUTPUTDir"};



open(LANCIA,">","lancia.sh") or die "Can't open file lancia.sh";

open(LIST,"./list.txt");
while(<LIST>)
{
  ($label,$X0,$Y0,$Z0,$PX0,$PY0,$PZ0,$NEVTS) = split(" ");
  print($label." ".$X0," ".$Y0." ".$Z0." ".$PX0." ".$PY0." ".$PZ0." ".$NEVTS."\n");
  
  $jobDir = $OUTPUTDir."/run_".$label."/";
  if( ! -e $jobDir )
  {
    #print("mkdir ".$jobDir."\n");
    system("mkdir ".$jobDir);
  }
  else
  {
    if( $ARGV[1] == 1 )
    {
      #print("rm -rf ".$jobDir."\n");
      system("rm -rf ".$jobDir);
      #print("mkdir ".$jobDir."\n");
      system("mkdir ".$jobDir);
    }
    else
    {
      print(">>> output directory not empty. Remove it or run ./launchJobs.pl params.cfg 1 <<< \n");
      die;
    }
  }
  
  #print("cp ".$CRYSTALCfg." ".$jobDir."\n");
  system("cp ".$CRYSTALCfg." ".$jobDir);
  
  $jobGpsMac = $jobDir."/gps.mac";
  system("cat ".$GPSMac."   | sed -e s%PX0%".$PX0.
                        "%g | sed -e s%PY0%".$PY0.
                        "%g | sed -e s%PZ0%".$PZ0.
                        "%g | sed -e s%X0%".$X0.
                        "%g | sed -e s%Y0%".$Y0.
                        "%g | sed -e s%Z0%".$Z0.
                        "%g | sed -e s%NEVTS%".$NEVTS.
                        "%g > ".$jobGpsMac);

  $jobOut = $jobDir."/out_".$label.".txt";
  
  $jobSh = $jobDir."/job_".$label.".sh";
  open(JOBSH,">",$jobSh) or die "Can't open file ".$jobSh;
  
  print JOBSH "echo \$SHELL\n";
  print JOBSH "cd ".$jobDir."\n";
  print JOBSH "pwd \n";
  print JOBSH "unbuffer LuAG_Fibers_Timing ".$jobDir."crystal.cfg out >& ".$jobOut."\n";
  
  print LANCIA "qsub -d ".$jobDir." -q shortcms ".$jobSh."\n";
}
