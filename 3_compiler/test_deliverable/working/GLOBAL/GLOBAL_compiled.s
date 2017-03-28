     .file     1 "file"       
     .section  .mdebug.abi32  
     .previous 
     .nan      legacy         
     .module   fp=xx          
     .module   nooddspreg     
     .abicalls 
     .text     
global:        
     .space    4
     .text     
     .align    2
     .globl    main
$LFB0= .
     .set      nomips16  
     .set      nomicromips
     .ent      globalfunc
     .type     globalfunc, @function
globalfunc:
     .frame    $fp,16,$31
     .mask     0x40000000,-4
     .fmask    0x00000000,0
     .set      noreorder
     .set      nomacro
     addiu     $sp,$sp,-16
     sw        $31,12($sp)
     sw        $fp,8($sp)
     move      $fp,$sp
#====== ASSEMBLY COMING ======
     li          $2,42
     sw          $2,4($fp)
     li          $2,1
#====== ASSEMBLY ENDING ======
     move      $sp,$fp
     lw        $31,12($sp)
     lw        $fp,8($sp)
     addiu     $sp,$sp,16
     j         $31 
     nop       
     .set      macro     
     .set      reorder   
     .end      globalfunc
     .size     globalfunc, .-globalfunc
