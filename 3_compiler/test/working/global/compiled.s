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
     .ent      main      
     .type     main,     @function
main:
     .frame    $fp,12,$31
     .mask     0x40000000,-4
     .fmask    0x00000000,0
     .set      noreorder
     .set      nomacro
     addiu     $sp,$sp,-12
     sw        $fp,8($sp)
     move      $fp,$sp
     lui       $28,%hi(__gnu_local_gp)
     addiu     $28,$28,%lo(__gnu_local_gp)
#====== ASSEMBLY COMING ======
     li          $2,3
     sw          $2,12($fp)
#LEFT--> x
#RIGHT--> 12
#GLOBAL EXISTS--> x
#RIGHT CONST--> 12
     lw          $2,%got(x)($28)
     li          $3,12
     sw          $3,4($2)
#LEFT--> x
#RIGHT--> t
#GLOBAL EXISTS--> x
#RIGHT VAR--> t
#LOCAL TO GLOBAL
     lw          $2,%got(x)($28)
     lw          $2,12($2)
     sw          $3,4($fp)
     li          $2,1
#====== ASSEMBLY ENDING ======
     move      $sp,$fp
     lw        $fp,8($sp)
     addiu     $sp,$sp,12
     j         $31 
     nop       
     .set      macro     
     .set      reorder   
     .end      main      
     .size     main, .-main
