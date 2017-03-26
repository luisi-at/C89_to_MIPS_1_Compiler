     .file     1 "file"       
     .section  .mdebug.abi32  
     .previous 
     .nan      legacy         
     .module   fp=xx          
     .module   nooddspreg     
     .abicalls 
     .text     
     .align    2         
     .globl    main      
     .set      nomips16  
     .set      nomicromips
     .ent      main      
     .type     main,     @function
$LFB0= .
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
     li          $2,3
     sw          $2,4($fp)
     lw          $2,4($fp)
     addiu       $2,13
     sw          $2,8($fp)
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
