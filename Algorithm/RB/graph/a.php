<?php

class A
{

    function __call($mName, $args)
    {
        echo "{$mName}'s args are {$args[0]}";
    }
}


$ob = new A();

$ob->unknownMethod(10);
