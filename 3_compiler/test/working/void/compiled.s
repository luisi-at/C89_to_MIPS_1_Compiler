     .file     1 "file"       
     .section  .mdebug.abi32  
     .previous 
     .nan      legacy         
     .module   fp=xx          
     .module   nooddspreg     
     .abicalls 
     .text     
x:             
     .space    4
     .text     
     .align    2
     .globl    main
y:
     .space    4
     .text     
     .align    2
     .globl    main
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
#====== ASSEMBLY COMING ======
     lui         $2,%hi(x)
     li          $3,3
     sw          $3,%lo(x)($2)
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
     .ent      main      
     .type     main,     @function
main:
     .frame    $fp,40,$31
     .mask     0x40000000,-4
     .fmask    0x00000000,0
     .set      noreorder
     .set      nomacro
     addiu     $sp,$sp,-40
     sw        $31,36($sp)
     sw        $fp,32($sp)
     move      $fp,$sp
#====== ASSEMBLY COMING ======
#VOID FUNCTION!
     .option pic0
     jal       function
     nop       

     .option pic2
     lui         $2,%hi(x)
     lw          $3,%lo(x)($2)
     li          $2,3
     bne         $2,$3,$L2
     nop       

     lui         $2,%hi(y)
     li          $3,4
     sw          $3,%lo(y)($2)
     move        $2,$0
     b          $L3
     nop       

$L2:
     move        $2,$0
     b          $L3
     nop       

$L3:
#====== ASSEMBLY ENDING ======
     move      $sp,$fp
     lw        $31,36($sp)
     lw        $fp,32($sp)
     addiu     $sp,$sp,40
     j         $31 
     nop       
     .set      macro     
     .set      reorder   
     .end      main      
     .size     main, .-main
