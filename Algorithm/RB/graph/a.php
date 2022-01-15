<?php

abstract class Model
{
    protected const TABLE_NAME = '';

    public static function all()
    {
        return 'SELECT * FROM ' . static::TABLE_NAME;
    }
}

class User extends Model
{
    protected const TABLE_NAME = 'users';
}

class Role extends Model
{
    protected const TABLE_NAME = 'roles';
}

echo User::all(); // SELECT * FROM users;
