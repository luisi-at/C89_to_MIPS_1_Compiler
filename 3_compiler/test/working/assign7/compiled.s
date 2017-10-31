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
     .frame    $fp,20,$31
     .mask     0x40000000,-4
     .fmask    0x00000000,0
     .set      noreorder
     .set      nomacro
     addiu     $sp,$sp,-20
     sw        $fp,16($sp)
     move      $fp,$sp
#====== ASSEMBLY COMING ======
#LEFT--> x
#RIGHT--> 0
#LEFT LOCAL--> x
     sw          $0,4($fp)
#LEFT--> y
#RIGHT--> 13
#LEFT LOCAL--> y
     li          $2,13
     sw          $2,8($fp)
#LEFT--> z
#RIGHT--> 3
#LEFT LOCAL--> z
     li          $2,3
     sw          $2,12($fp)
     lw         $2,12($fp)
     addiu     $3,$2,1
     sw         $3,12($fp)
#LEFT--> y
#RIGHT--> z
#LEFT LOCAL--> y
     sw          $2,8($fp)
#LEFT--> x
#RIGHT--> 
#LEFT LOCAL--> x
#GLOBAL TO LOCAL
     move        $2,$0
#====== ASSEMBLY ENDING ======
     move      $sp,$fp
     lw        $fp,16($sp)
     addiu     $sp,$sp,20
     j         $31 
     nop       
     .set      macro     
     .set      reorder   
     .end      main      
     .size     main, .-main
