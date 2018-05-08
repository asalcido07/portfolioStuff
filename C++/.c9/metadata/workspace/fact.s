{"filter":false,"title":"fact.s","tooltip":"/fact.s","undoManager":{"mark":44,"position":44,"stack":[[{"start":{"row":0,"column":0},"end":{"row":38,"column":46},"action":"insert","lines":["! main for factorial program","        loadi  0 1     ! line 0, R0 = fact(R1)","        read   1       ! input R1","        call   6       ! call fact","        load   0 33    ! receive result of fact","        write  0","        halt","! fact function","        compri 1 1     ! line 6","        jumpe  14      ! jump over the recursive call to fact if","        jumpl  14      ! R1 is less than or equal 1","        call   16      ! call mult (R0 = R0 * R1)","        load   0 34    ! receive result of mult","        subi   1 1     ! decrement multiplier (R1) and multiply again","        call   6       ! call fact","        load   0 33","        store  0 33    ! line 14, return R0 (result of fact)","        return","! mult function","        loadi  2 8     ! line 16, init R2 (counter)","        loadi  3 0     ! init R3 (result of mult)","        shr    1       ! line 18 (loop), shift right multiplier set CARRY","        store  2 35    ! save counter","        getstat 2      ! to find CARRY's value        ","        andi   2 1","        compri 2 1","        jumpe  25      ! if CARRY==1 add","        jump   26      ! otherwise do nothing","        add    3 0","        shl    0       ! make multiplicand ready for next add","        load   2 35    ! restore counter","        subi   2 1     ! decrement counter        ","        compri 2 0     ! if counter > 0 jump to loop","        jumpg  18","        store  3 34    ! return R3 (result of mult)","        return","        noop           ! line 33, fact return value","        noop           ! line 34, mult return value","        noop           ! line 35, mult counter"],"id":1}],[{"start":{"row":0,"column":0},"end":{"row":0,"column":28},"action":"remove","lines":["! main for factorial program"],"id":2}],[{"start":{"row":7,"column":0},"end":{"row":7,"column":15},"action":"remove","lines":["! fact function"],"id":3}],[{"start":{"row":18,"column":0},"end":{"row":18,"column":15},"action":"remove","lines":["! mult function"],"id":4}],[{"start":{"row":1,"column":23},"end":{"row":1,"column":46},"action":"remove","lines":["! line 0, R0 = fact(R1)"],"id":5}],[{"start":{"row":2,"column":23},"end":{"row":2,"column":33},"action":"remove","lines":["! input R1"],"id":6}],[{"start":{"row":3,"column":23},"end":{"row":3,"column":34},"action":"remove","lines":["! call fact"],"id":7}],[{"start":{"row":4,"column":23},"end":{"row":4,"column":47},"action":"remove","lines":["! receive result of fact"],"id":8}],[{"start":{"row":16,"column":23},"end":{"row":16,"column":60},"action":"remove","lines":["! line 14, return R0 (result of fact)"],"id":9}],[{"start":{"row":14,"column":23},"end":{"row":14,"column":34},"action":"remove","lines":["! call fact"],"id":10}],[{"start":{"row":13,"column":23},"end":{"row":13,"column":69},"action":"remove","lines":["! decrement multiplier (R1) and multiply again"],"id":11}],[{"start":{"row":12,"column":23},"end":{"row":12,"column":47},"action":"remove","lines":["! receive result of mult"],"id":12}],[{"start":{"row":11,"column":23},"end":{"row":11,"column":49},"action":"remove","lines":["! call mult (R0 = R0 * R1)"],"id":13}],[{"start":{"row":10,"column":23},"end":{"row":10,"column":51},"action":"remove","lines":["! R1 is less than or equal 1"],"id":14}],[{"start":{"row":9,"column":23},"end":{"row":9,"column":64},"action":"remove","lines":["! jump over the recursive call to fact if"],"id":15}],[{"start":{"row":8,"column":23},"end":{"row":8,"column":31},"action":"remove","lines":["! line 6"],"id":16}],[{"start":{"row":23,"column":23},"end":{"row":23,"column":50},"action":"remove","lines":["! to find CARRY's value    "],"id":17}],[{"start":{"row":22,"column":23},"end":{"row":22,"column":37},"action":"remove","lines":["! save counter"],"id":18}],[{"start":{"row":21,"column":23},"end":{"row":21,"column":73},"action":"remove","lines":["! line 18 (loop), shift right multiplier set CARRY"],"id":19}],[{"start":{"row":20,"column":23},"end":{"row":20,"column":49},"action":"remove","lines":["! init R3 (result of mult)"],"id":20}],[{"start":{"row":19,"column":23},"end":{"row":19,"column":51},"action":"remove","lines":["! line 16, init R2 (counter)"],"id":21}],[{"start":{"row":38,"column":23},"end":{"row":38,"column":46},"action":"remove","lines":["! line 35, mult counter"],"id":22}],[{"start":{"row":37,"column":23},"end":{"row":37,"column":51},"action":"remove","lines":["! line 34, mult return value"],"id":23}],[{"start":{"row":36,"column":23},"end":{"row":36,"column":51},"action":"remove","lines":["! line 33, fact return value"],"id":24}],[{"start":{"row":34,"column":23},"end":{"row":34,"column":51},"action":"remove","lines":["! return R3 (result of mult)"],"id":25}],[{"start":{"row":32,"column":23},"end":{"row":32,"column":52},"action":"remove","lines":["! if counter > 0 jump to loop"],"id":26}],[{"start":{"row":31,"column":23},"end":{"row":31,"column":46},"action":"remove","lines":["! decrement counter    "],"id":27}],[{"start":{"row":30,"column":22},"end":{"row":30,"column":40},"action":"remove","lines":[" ! restore counter"],"id":28}],[{"start":{"row":29,"column":23},"end":{"row":29,"column":61},"action":"remove","lines":["! make multiplicand ready for next add"],"id":29}],[{"start":{"row":27,"column":21},"end":{"row":27,"column":45},"action":"remove","lines":["  ! otherwise do nothing"],"id":30}],[{"start":{"row":26,"column":22},"end":{"row":26,"column":40},"action":"remove","lines":[" ! if CARRY==1 add"],"id":31}],[{"start":{"row":1,"column":0},"end":{"row":1,"column":4},"action":"remove","lines":["    "],"id":32},{"start":{"row":2,"column":0},"end":{"row":2,"column":4},"action":"remove","lines":["    "]},{"start":{"row":3,"column":0},"end":{"row":3,"column":4},"action":"remove","lines":["    "]},{"start":{"row":4,"column":0},"end":{"row":4,"column":4},"action":"remove","lines":["    "]},{"start":{"row":5,"column":0},"end":{"row":5,"column":4},"action":"remove","lines":["    "]},{"start":{"row":6,"column":0},"end":{"row":6,"column":4},"action":"remove","lines":["    "]},{"start":{"row":8,"column":0},"end":{"row":8,"column":4},"action":"remove","lines":["    "]},{"start":{"row":9,"column":0},"end":{"row":9,"column":4},"action":"remove","lines":["    "]},{"start":{"row":10,"column":0},"end":{"row":10,"column":4},"action":"remove","lines":["    "]},{"start":{"row":11,"column":0},"end":{"row":11,"column":4},"action":"remove","lines":["    "]},{"start":{"row":12,"column":0},"end":{"row":12,"column":4},"action":"remove","lines":["    "]},{"start":{"row":13,"column":0},"end":{"row":13,"column":4},"action":"remove","lines":["    "]},{"start":{"row":14,"column":0},"end":{"row":14,"column":4},"action":"remove","lines":["    "]},{"start":{"row":15,"column":0},"end":{"row":15,"column":4},"action":"remove","lines":["    "]},{"start":{"row":16,"column":0},"end":{"row":16,"column":4},"action":"remove","lines":["    "]},{"start":{"row":17,"column":0},"end":{"row":17,"column":4},"action":"remove","lines":["    "]},{"start":{"row":19,"column":0},"end":{"row":19,"column":4},"action":"remove","lines":["    "]},{"start":{"row":20,"column":0},"end":{"row":20,"column":4},"action":"remove","lines":["    "]},{"start":{"row":21,"column":0},"end":{"row":21,"column":4},"action":"remove","lines":["    "]},{"start":{"row":22,"column":0},"end":{"row":22,"column":4},"action":"remove","lines":["    "]},{"start":{"row":23,"column":0},"end":{"row":23,"column":4},"action":"remove","lines":["    "]},{"start":{"row":24,"column":0},"end":{"row":24,"column":4},"action":"remove","lines":["    "]},{"start":{"row":25,"column":0},"end":{"row":25,"column":4},"action":"remove","lines":["    "]},{"start":{"row":26,"column":0},"end":{"row":26,"column":4},"action":"remove","lines":["    "]},{"start":{"row":27,"column":0},"end":{"row":27,"column":4},"action":"remove","lines":["    "]},{"start":{"row":28,"column":0},"end":{"row":28,"column":4},"action":"remove","lines":["    "]},{"start":{"row":29,"column":0},"end":{"row":29,"column":4},"action":"remove","lines":["    "]},{"start":{"row":30,"column":0},"end":{"row":30,"column":4},"action":"remove","lines":["    "]},{"start":{"row":31,"column":0},"end":{"row":31,"column":4},"action":"remove","lines":["    "]},{"start":{"row":32,"column":0},"end":{"row":32,"column":4},"action":"remove","lines":["    "]},{"start":{"row":33,"column":0},"end":{"row":33,"column":4},"action":"remove","lines":["    "]},{"start":{"row":34,"column":0},"end":{"row":34,"column":4},"action":"remove","lines":["    "]},{"start":{"row":35,"column":0},"end":{"row":35,"column":4},"action":"remove","lines":["    "]},{"start":{"row":36,"column":0},"end":{"row":36,"column":4},"action":"remove","lines":["    "]},{"start":{"row":37,"column":0},"end":{"row":37,"column":4},"action":"remove","lines":["    "]},{"start":{"row":38,"column":0},"end":{"row":38,"column":4},"action":"remove","lines":["    "]}],[{"start":{"row":1,"column":0},"end":{"row":1,"column":4},"action":"remove","lines":["    "],"id":33},{"start":{"row":2,"column":0},"end":{"row":2,"column":4},"action":"remove","lines":["    "]},{"start":{"row":3,"column":0},"end":{"row":3,"column":4},"action":"remove","lines":["    "]},{"start":{"row":4,"column":0},"end":{"row":4,"column":4},"action":"remove","lines":["    "]},{"start":{"row":5,"column":0},"end":{"row":5,"column":4},"action":"remove","lines":["    "]},{"start":{"row":6,"column":0},"end":{"row":6,"column":4},"action":"remove","lines":["    "]},{"start":{"row":8,"column":0},"end":{"row":8,"column":4},"action":"remove","lines":["    "]},{"start":{"row":9,"column":0},"end":{"row":9,"column":4},"action":"remove","lines":["    "]},{"start":{"row":10,"column":0},"end":{"row":10,"column":4},"action":"remove","lines":["    "]},{"start":{"row":11,"column":0},"end":{"row":11,"column":4},"action":"remove","lines":["    "]},{"start":{"row":12,"column":0},"end":{"row":12,"column":4},"action":"remove","lines":["    "]},{"start":{"row":13,"column":0},"end":{"row":13,"column":4},"action":"remove","lines":["    "]},{"start":{"row":14,"column":0},"end":{"row":14,"column":4},"action":"remove","lines":["    "]},{"start":{"row":15,"column":0},"end":{"row":15,"column":4},"action":"remove","lines":["    "]},{"start":{"row":16,"column":0},"end":{"row":16,"column":4},"action":"remove","lines":["    "]},{"start":{"row":17,"column":0},"end":{"row":17,"column":4},"action":"remove","lines":["    "]},{"start":{"row":19,"column":0},"end":{"row":19,"column":4},"action":"remove","lines":["    "]},{"start":{"row":20,"column":0},"end":{"row":20,"column":4},"action":"remove","lines":["    "]},{"start":{"row":21,"column":0},"end":{"row":21,"column":4},"action":"remove","lines":["    "]},{"start":{"row":22,"column":0},"end":{"row":22,"column":4},"action":"remove","lines":["    "]},{"start":{"row":23,"column":0},"end":{"row":23,"column":4},"action":"remove","lines":["    "]},{"start":{"row":24,"column":0},"end":{"row":24,"column":4},"action":"remove","lines":["    "]},{"start":{"row":25,"column":0},"end":{"row":25,"column":4},"action":"remove","lines":["    "]},{"start":{"row":26,"column":0},"end":{"row":26,"column":4},"action":"remove","lines":["    "]},{"start":{"row":27,"column":0},"end":{"row":27,"column":4},"action":"remove","lines":["    "]},{"start":{"row":28,"column":0},"end":{"row":28,"column":4},"action":"remove","lines":["    "]},{"start":{"row":29,"column":0},"end":{"row":29,"column":4},"action":"remove","lines":["    "]},{"start":{"row":30,"column":0},"end":{"row":30,"column":4},"action":"remove","lines":["    "]},{"start":{"row":31,"column":0},"end":{"row":31,"column":4},"action":"remove","lines":["    "]},{"start":{"row":32,"column":0},"end":{"row":32,"column":4},"action":"remove","lines":["    "]},{"start":{"row":33,"column":0},"end":{"row":33,"column":4},"action":"remove","lines":["    "]},{"start":{"row":34,"column":0},"end":{"row":34,"column":4},"action":"remove","lines":["    "]},{"start":{"row":35,"column":0},"end":{"row":35,"column":4},"action":"remove","lines":["    "]},{"start":{"row":36,"column":0},"end":{"row":36,"column":4},"action":"remove","lines":["    "]},{"start":{"row":37,"column":0},"end":{"row":37,"column":4},"action":"remove","lines":["    "]},{"start":{"row":38,"column":0},"end":{"row":38,"column":4},"action":"remove","lines":["    "]}],[{"start":{"row":0,"column":0},"end":{"row":1,"column":0},"action":"remove","lines":["",""],"id":34}],[{"start":{"row":5,"column":4},"end":{"row":6,"column":0},"action":"remove","lines":["",""],"id":35}],[{"start":{"row":15,"column":6},"end":{"row":16,"column":0},"action":"remove","lines":["",""],"id":36}],[{"start":{"row":35,"column":15},"end":{"row":36,"column":0},"action":"insert","lines":["",""],"id":37}],[{"start":{"row":0,"column":0},"end":{"row":36,"column":0},"action":"remove","lines":["loadi  0 1     ","read   1       ","call   6       ","load   0 33    ","write  0","halt","compri 1 1     ","jumpe  14      ","jumpl  14      ","call   16      ","load   0 34    ","subi   1 1     ","call   6       ","load   0 33","store  0 33    ","return","loadi  2 8     ","loadi  3 0     ","shr    1       ","store  2 35    ","getstat 2          ","andi   2 1","compri 2 1","jumpe  25     ","jump   26    ","add    3 0","shl    0       ","load   2 35   ","subi   2 1         ","compri 2 0     ","jumpg  18","store  3 34    ","return","noop           ","noop           ","noop           ",""],"id":38},{"start":{"row":0,"column":0},"end":{"row":38,"column":46},"action":"insert","lines":["! main for factorial program","        loadi  0 1     ! line 0, R0 = fact(R1)","        read   1       ! input R1","        call   6       ! call fact","        load   0 33    ! receive result of fact","        write  0","        halt","! fact function","        compri 1 1     ! line 6","        jumpe  14      ! jump over the recursive call to fact if","        jumpl  14      ! R1 is less than or equal 1","        call   16      ! call mult (R0 = R0 * R1)","        load   0 34    ! receive result of mult","        subi   1 1     ! decrement multiplier (R1) and multiply again","        call   6       ! call fact","        load   0 33","        store  0 33    ! line 14, return R0 (result of fact)","        return","! mult function","        loadi  2 8     ! line 16, init R2 (counter)","        loadi  3 0     ! init R3 (result of mult)","        shr    1       ! line 18 (loop), shift right multiplier set CARRY","        store  2 35    ! save counter","        getstat 2      ! to find CARRY's value        ","        andi   2 1","        compri 2 1","        jumpe  25      ! if CARRY==1 add","        jump   26      ! otherwise do nothing","        add    3 0","        shl    0       ! make multiplicand ready for next add","        load   2 35    ! restore counter","        subi   2 1     ! decrement counter        ","        compri 2 0     ! if counter > 0 jump to loop","        jumpg  18","        store  3 34    ! return R3 (result of mult)","        return","        noop           ! line 33, fact return value","        noop           ! line 34, mult return value","        noop           ! line 35, mult counter"]}],[{"start":{"row":38,"column":46},"end":{"row":39,"column":0},"action":"insert","lines":["",""],"id":39},{"start":{"row":39,"column":0},"end":{"row":39,"column":8},"action":"insert","lines":["        "]}],[{"start":{"row":1,"column":46},"end":{"row":1,"column":47},"action":"insert","lines":[" "],"id":40}],[{"start":{"row":1,"column":46},"end":{"row":1,"column":47},"action":"remove","lines":[" "],"id":41}],[{"start":{"row":19,"column":17},"end":{"row":19,"column":18},"action":"remove","lines":["8"],"id":42},{"start":{"row":19,"column":17},"end":{"row":19,"column":18},"action":"insert","lines":["2"]}],[{"start":{"row":19,"column":17},"end":{"row":19,"column":18},"action":"remove","lines":["2"],"id":43},{"start":{"row":19,"column":17},"end":{"row":19,"column":18},"action":"insert","lines":["4"]}],[{"start":{"row":19,"column":17},"end":{"row":19,"column":18},"action":"remove","lines":["4"],"id":44},{"start":{"row":19,"column":17},"end":{"row":19,"column":18},"action":"insert","lines":["1"]}],[{"start":{"row":19,"column":17},"end":{"row":19,"column":18},"action":"remove","lines":["1"],"id":45},{"start":{"row":19,"column":17},"end":{"row":19,"column":18},"action":"insert","lines":["8"]}]]},"ace":{"folds":[],"scrolltop":188,"scrollleft":0,"selection":{"start":{"row":19,"column":18},"end":{"row":19,"column":18},"isBackwards":false},"options":{"guessTabSize":true,"useWrapMode":false,"wrapToView":true},"firstLineState":{"row":12,"state":"start","mode":"ace/mode/text"}},"timestamp":1461710372752,"hash":"47a8d9950d820dbff1c1f145e6b80e0cf7cc5a1f"}