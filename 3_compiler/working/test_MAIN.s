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
     .frame    $fp,4,$31
     .mask     0x40000000,-4
     .fmask    0x00000000,0
     .set      noreorder
     .set      nomacro
     addiu     $sp,$sp,-4
     sw        $fp,0($sp)
     move      $fp,$sp
#====== ASSEMBLY COMING ======
     move        $2,$0
#====== ASSEMBLY ENDING ======
     move      $sp,$fp
     lw        $fp,0($sp)
     addiu     $sp,$sp,4
     j         $31 
     nop       
     .set      macro     
     .set      reorder   
     .end      main      
     .size     main, .-main
