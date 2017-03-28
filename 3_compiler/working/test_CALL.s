     .file     1 "file"       
     .section  .mdebug.abi32  
     .previous 
     .nan      legacy         
     .module   fp=xx          
     .module   nooddspreg     
     .abicalls 
     .text     
     .comm     name,4,4

$LFB0= .
     .set      nomips16  
     .set      nomicromips
     .ent      f         
     .type     f,        @function
f:
     .frame    $fp,16,$31
     .mask     0x40000000,-4
     .fmask    0x00000000,0
     .set      noreorder
     .set      nomacro
     addiu     $sp,$sp,-16
     sw        $31,12($sp)
     sw        $fp,8($sp)
     move      $fp,$sp
     lui       $28,%hi(__gnu_local_gp)
     addiu     $28,$28,%lo(__gnu_local_gp)
#====== ASSEMBLY COMING ======
#VOID FUNCTION!
     .option pic0
     jal          g
     nop       

     .option pic2
     lw        %28,16(%fp)
#====== ASSEMBLY ENDING ======
     move      $sp,$fp
     lw        $31,12($sp)
     lw        $fp,8($sp)
     addiu     $sp,$sp,16
     j         $31 
     nop       
     .set      macro     
     .set      reorder   
     .end      f         
     .size     f, .-f    
