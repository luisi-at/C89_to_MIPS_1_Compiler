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
     .globl    ffff      
     .set      nomips16  
     .set      nomicromips
     .ent      ffff      
     .type     ffff,     @function
ffff:
     .frame    $fp,20,$31
     .mask     0x40000000,-4
     .fmask    0x00000000,0
     .set      noreorder
     .set      nomacro
     addiu     $sp,$sp,-20
     sw        $31,16($sp)
     sw        $fp,12($sp)
     move      $fp,$sp
#====== ASSEMBLY COMING ======
#LEFT--> x
#RIGHT--> 10
#LEFT LOCAL--> x
     li          $2,10
     sw          $2,4($fp)
     lw          $2,4($fp)
#====== ASSEMBLY ENDING ======
     move      $sp,$fp
     lw        $31,16($sp)
     lw        $fp,12($sp)
     addiu     $sp,$sp,20
     j         $31 
     nop       
     .set      macro     
     .set      reorder   
     .end      ffff      
     .size     ffff, .-ffff
