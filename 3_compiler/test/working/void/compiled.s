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
     li          $2,5
     sw          $2,4($fp)
     li          $2,4
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
     .frame    $fp,36,$31
     .mask     0x40000000,-4
     .fmask    0x00000000,0
     .set      noreorder
     .set      nomacro
     addiu     $sp,$sp,-36
     sw        $31,32($sp)
     sw        $fp,28($sp)
     move      $fp,$sp
     .cprestore  16
#====== ASSEMBLY COMING ======
#VOID FUNCTION!
     .option pic0
     jal       function
     nop       

     .option pic2
     move        $2,$0
#====== ASSEMBLY ENDING ======
     move      $sp,$fp
     lw        $31,32($sp)
     lw        $fp,28($sp)
     addiu     $sp,$sp,36
     j         $31 
     nop       
     .set      macro     
     .set      reorder   
     .end      main      
     .size     main, .-main
