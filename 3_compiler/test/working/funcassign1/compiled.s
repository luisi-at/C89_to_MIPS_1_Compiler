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
     .globl    function  
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
     li          $2,18
     sw          $2,4($fp)
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
     .align    2         
     .globl    main      
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
     .option pic0
     jal       function
     nop       

     .option pic2
     sw          $2,24($fp)
     lw          $2,24($fp)
     slt         $2,$2,11
     bne         $2,$0,$L2
     nop       

     li          $2,2
     sw          $2,28($fp)
     li          $2,3
     sw          $2,28($fp)
$L2:
     move        $2,$0
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
