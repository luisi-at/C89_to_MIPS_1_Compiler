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
     .frame    $fp,8,$31
     .mask     0x40000000,-4
     .fmask    0x00000000,0
     .set      noreorder
     .set      nomacro
     addiu     $sp,$sp,-8
     sw        $fp,4($sp)
     move      $fp,$sp
#====== ASSEMBLY COMING ======
$L3:
     lw         $2,4($fp)
     addiu     $2,$2,1
     sw         $2,4($fp)
     lw          $2,4($fp)
     slt         $2,$2,4
     beq         $2,$0,$L2
     nop       

     b          $L3
     nop       

 $L2:
     move        $2,$0
#====== ASSEMBLY ENDING ======
     move      $sp,$fp
     lw        $fp,4($sp)
     addiu     $sp,$sp,8
     j         $31 
     nop       
     .set      macro     
     .set      reorder   
     .end      main      
     .size     main, .-main
