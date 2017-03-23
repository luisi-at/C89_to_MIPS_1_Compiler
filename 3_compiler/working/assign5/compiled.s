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
main:
     .frame    $fp,24,$31
     .mask     0x40000000,-4
     .fmask    0x00000000,0
     .set      noreorder
     .set      nomacro
     addiu     $sp,$sp,-24
     sw        $fp,20($sp)
#====== ASSEMBLY COMING ======
ASSIGNMENT CODGEN
ASSIGNMENT CODGEN
     sw          $0,4($fp)
ASSIGNMENT CODGEN
ASSIGNMENT CODGEN
     li          $2,13
     sw          $2,8($fp)
ASSIGNMENT CODGEN
MULTIPLE RECURSION 1
     lw         $2,8($fp)
     addiu     $3,$2,1
     sw         $3,8($fp)
ASSIGNMENT CODGEN
     lw          $2,8($fp)
     sw          $2,4($fp)
     move        $2,$0
#====== ASSEMBLY ENDING ======
     move      $sp,$fp
     lw        $fp,20($sp)
     addiu     $sp,$sp,24
     j         $31 
     nop       
     .set      macro     
     .set      reorder   
     .end      main      
     .size     main, .-main
