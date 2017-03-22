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
     .frame    $fp,16,$31
     .mask     0x40000000,-4
     .fmask    0x00000000,0
     .set      noreorder
     .set      nomacro
     addiu     $sp,$sp,-16
     sw        $fp,12($sp)
#====== ASSEMBLY COMING ======
ASSIGNMENT CODGEN
ASSIGNMENT CODGEN OPERATOR--> =
CONST BOOL--> 0
     lw          $2,38952320($fp)
     sw          $2,38952320($fp)
#====== ASSEMBLY ENDING ======
     move      $sw,$fp
     lw        $fp,12($sp)
     addiu     $sp,$sp,16
     j         $31 
     nop       
     .set      macro     
     .set      reorder   
     .end      main      
     .size     main, .-main
