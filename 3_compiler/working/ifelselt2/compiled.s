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
     .frame    $fp,24,$31
     .mask     0x40000000,-4
     .fmask    0x00000000,0
     .set      noreorder
     .set      nomacro
     addiu     $sp,$sp,-24
     sw        $fp,20($sp)
     move      $fp,$sp
#====== ASSEMBLY COMING ======
     li          $2,4
     sw          $2,8($fp)
     li          $2,2
     sw          $2,4($fp)
     lw          $2,4($fp)
     lw          $3,8($fp)
     slt         $2,$3,$2
     beq         $2,$0,$L2
     nop       

     li          $2,30
     sw          $2,4($fp)
     b            $L3
     nop       

 $L2:
     lw          $2,4($fp)
     slt         $2,$2,2
     beq         $2,$0,$L4
     nop       

     sw          $0,4($fp)
$L4:
$L3:
     move        $2,$0
#====== ASSEMBLY ENDING ======
     move      $sp,$fp
     lw        $fp,20($sp)
     addiu     $sp,$sp,24
     j         $31 
     nop       
     .set      macro     
     .set      reorder   
     .end      main      
     .size     main, .-main
