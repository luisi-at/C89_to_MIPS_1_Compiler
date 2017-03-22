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
MAKE BINDING
ASSIGNMENT CODGEN OPERATOR--> =
CONST BOOL--> 1
CONTEXT MEM OFFSET--> 8
LEFT--> xname
THIS STORED OFFSET--> 4
RIGHT--> 1
     li          $2,1
     sw          $2,4($fp)
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
