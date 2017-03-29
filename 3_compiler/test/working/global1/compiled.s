     .file     1 "file"       
     .section  .mdebug.abi32  
     .previous 
     .nan      legacy         
     .module   fp=xx          
     .module   nooddspreg     
     .abicalls 
     .text     
     .comm     name,4,4

     .comm     name,4,4

$LFB0= .
     .set      nomips16  
     .set      nomicromips
     .ent      function  
     .type     function, @function
function:
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
#LEFT--> x
#RIGHT--> 14
#GLOBAL EXISTS--> x
#RIGHT CONST--> 14
     lw          $2,%got(x)($28)
     li          $3,14
     sw          $3,4($2)
#====== ASSEMBLY ENDING ======
     move      $sp,$fp
     lw        $31,12($sp)
     lw        $fp,8($sp)
     addiu     $sp,$sp,16
     j         $31 
     nop       
     .set      macro     
     .set      reorder   
     .end      function  
     .size     function, .-function
$LFB1= .
     .set      nomips16  
     .set      nomicromips
     .ent      function2 
     .type     function2, @function
function2:
     .frame    $fp,44,$31
     .mask     0x40000000,-4
     .fmask    0x00000000,0
     .set      noreorder
     .set      nomacro
     addiu     $sp,$sp,-44
     sw        $31,40($sp)
     sw        $fp,36($sp)
     move      $fp,$sp
     lui       $28,%hi(__gnu_local_gp)
     addiu     $28,$28,%lo(__gnu_local_gp)
#====== ASSEMBLY COMING ======
#LEFT--> x
#RIGHT--> 13
#GLOBAL EXISTS--> x
#RIGHT CONST--> 13
     lw          $2,%got(x)($28)
     li          $3,13
     sw          $3,4($2)
#====== ASSEMBLY ENDING ======
     move      $sp,$fp
     lw        $31,40($sp)
     lw        $fp,36($sp)
     addiu     $sp,$sp,44
     j         $31 
     nop       
     .set      macro     
     .set      reorder   
     .end      function2 
     .size     function2, .-function2
$LFB2= .
     .set      nomips16  
     .set      nomicromips
     .ent      main      
     .type     main,     @function
main:
     .frame    $fp,80,$31
     .mask     0x40000000,-4
     .fmask    0x00000000,0
     .set      noreorder
     .set      nomacro
     addiu     $sp,$sp,-80
     sw        $31,76($sp)
     sw        $fp,72($sp)
     move      $fp,$sp
     lui       $28,%hi(__gnu_local_gp)
     addiu     $28,$28,%lo(__gnu_local_gp)
     .cprestore  16
#====== ASSEMBLY COMING ======
#LEFT--> x
#RIGHT--> 3
#GLOBAL EXISTS--> x
#RIGHT CONST--> 3
     lw          $2,%got(x)($28)
     li          $3,3
     sw          $3,4($2)
     lui         $2,%hi
     lw          $2,%lo($2)
     addiu       $3,$2,5
#LEFT--> y
#RIGHT--> x
#GLOBAL EXISTS--> y
     sw          $2,8($2)
#VOID FUNCTION!
     .option pic0
     jal       function
     nop       

     .option pic2
     lw        %28,16(%fp)
#VOID FUNCTION!
     .option pic3
     jal       function2
     nop       

     .option pic4
     lw        %28,16(%fp)
     lui         $2,%hi
     lw          $2,%lo($2)
     slt         $2,$2,4
     bne         $2,$0,$L2
     nop       

#LEFT--> y
#RIGHT--> 3
#GLOBAL EXISTS--> y
#RIGHT CONST--> 3
     lw          $2,%got(y)($28)
     li          $3,3
     sw          $3,8($2)
     move        $2,$0
     b          $L3
     nop       

$L2:
     li          $2,1
     b          $L3
     nop       

$L3:
#====== ASSEMBLY ENDING ======
     move      $sp,$fp
     lw        $31,76($sp)
     lw        $fp,72($sp)
     addiu     $sp,$sp,80
     j         $31 
     nop       
     .set      macro     
     .set      reorder   
     .end      main      
     .size     main, .-main
