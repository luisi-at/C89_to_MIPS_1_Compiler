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
     .frame    $fp,12,$31
     .mask     0x40000000,-4
     .fmask    0x00000000,0
     .set      noreorder
     .set      nomacro
     addiu     $sp,$sp,-12
     sw        $fp,8($sp)
     move      $fp,$sp
#====== ASSEMBLY COMING ======
#LEFT--> x
#RIGHT--> 1
#LEFT LOCAL--> x
     li          $2,1
     sw          $2,4($fp)
     lw          $2,4($fp)
     andi        $2,13
#LEFT--> x
#RIGHT--> 13
#LEFT LOCAL--> x
     sw          $2,4($fp)
     lw          $2,4($fp)
#====== ASSEMBLY ENDING ======
     move      $sp,$fp
     lw        $fp,8($sp)
     addiu     $sp,$sp,12
     j         $31 
     nop       
     .set      macro     
     .set      reorder   
     .end      main      
     .size     main, .-main
