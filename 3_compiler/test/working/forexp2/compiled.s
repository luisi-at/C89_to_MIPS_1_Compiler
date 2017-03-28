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
     .frame    $fp,12,$31
     .mask     0x40000000,-4
     .fmask    0x00000000,0
     .set      noreorder
     .set      nomacro
     addiu     $sp,$sp,-12
     sw        $fp,8($sp)
     move      $fp,$sp
#====== ASSEMBLY COMING ======
     li          $2,1
     sw          $2,8($fp)
     sw          $0,4($fp)
$L3:
     lw          $2,4($fp)
     slt         $2,$2,5
     bne         $2,$0,$L2
     nop       

     lw          $2,4($fp)
     li          $3,3
     bne         $2,$3,$L4
     nop       

     lw          $2,8($fp)
     addiu       $2,$2,4
     sw          $2,8($fp)
     b            $L5
     nop       

 $L4:
     lw         $2,8($fp)
     addiu     $2,$2,1
     sw         $2,8($fp)
$L5:
     lw         $2,4($fp)
     addiu     $2,$2,1
     sw         $2,4($fp)
     b          $L3
     nop       

 $L2:
     lw          $2,8($fp)
     addiu       $2,$2,2
     lw          $2,8($fp)
     addiu       $2,$2,2
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
