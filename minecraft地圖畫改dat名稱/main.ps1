Get-ChildItem *.dat | ForEach-Object -Begin {
  $count = 1
} -Process {
  Rename-Item $_ -NewName "map_$count.dat"
  $count++
}
