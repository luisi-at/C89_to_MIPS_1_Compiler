     .file     1 "file"       
     .section  .mdebug.abi32  
     .previous 
     .nan      legacy         
     .module   fp=xx          
     .module   nooddspreg     
     .abicalls 
     .text     
$LFB0= .       
     .align    2         
     .globl    main      
     .set      nomips16  
     .set      nomicromips
     .ent      main      
     .type     main,     @function
main:
     .frame    $fp,16,$31
     .mask     0x40000000,-4
     .fmask    0x00000000,0
     .set      noreorder
     .set      nomacro
     addiu     $sp,$sp,-16
     sw        $fp,12($sp)
     move      $fp,$sp
#====== ASSEMBLY COMING ======
#LEFT--> x
#RIGHT--> 12
#LEFT LOCAL--> x
     li          $2,12
     sw          $2,4($fp)
#LEFT--> y
#RIGHT--> 6
#LEFT LOCAL--> y
     li          $2,6
     sw          $2,8($fp)
     lw          $2,4($fp)
     lw          $3,8($fp)
     mult        $2,$3
     mflo        $2
#LEFT--> x
#RIGHT--> x
#LEFT LOCAL--> x
     sw          $2,4($fp)
     move        $2,$0
#====== ASSEMBLY ENDING ======
     move      $sp,$fp
     lw        $fp,12($sp)
     addiu     $sp,$sp,16
     j         $31 
     nop       
     .set      macro     
     .set      reorder   
     .end      main      
     .size     main, .-main
