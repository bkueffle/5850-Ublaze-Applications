connect -url tcp:127.0.0.1:3121
targets -set -filter {jtag_cable_name =~ "Digilent Arty S7 - 50 210352A6C016A" && level==0} -index 0
fpga -file C:/Users/Benjamin/Documents/Word-documents/CPP/ECE-5850/5850-Ublaze-Applications/src/uBlaze_Applications/uBlaze_Applications.sdk/base_mb_wrapper_hw_platform_0/base_mb_wrapper.bit
configparams mdm-detect-bscan-mask 2
targets -set -nocase -filter {name =~ "microblaze*#0" && bscan=="USER2"  && jtag_cable_name =~ "Digilent Arty S7 - 50 210352A6C016A"} -index 0
rst -system
after 3000
targets -set -nocase -filter {name =~ "microblaze*#0" && bscan=="USER2"  && jtag_cable_name =~ "Digilent Arty S7 - 50 210352A6C016A"} -index 0
dow C:/Users/Benjamin/Documents/Word-documents/CPP/ECE-5850/5850-Ublaze-Applications/src/uBlaze_Applications/uBlaze_Applications.sdk/hello_world/Debug/hello_world.elf
targets -set -nocase -filter {name =~ "microblaze*#0" && bscan=="USER2"  && jtag_cable_name =~ "Digilent Arty S7 - 50 210352A6C016A"} -index 0
con
