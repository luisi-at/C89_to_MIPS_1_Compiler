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
#LEFT--> y
#RIGHT--> 4
#LEFT LOCAL--> y
     li          $2,4
     sw          $2,8($fp)
#LEFT--> x
#RIGHT--> 2
#LEFT LOCAL--> x
     li          $2,2
     sw          $2,4($fp)
     lw          $2,4($fp)
     slt         $2,$2,2
     beq         $2,$0,$L2
     nop       

#LEFT--> x
#RIGHT--> 30
#LEFT LOCAL--> x
     li          $2,30
     sw          $2,4($fp)
$L2:
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
