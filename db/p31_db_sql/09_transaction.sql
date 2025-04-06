-- ACID
-- A (атомарность)
-- C (согласованность)
-- I (изолированность)
-- D (надёжность)

-- Типы транзакций
-- 1. Явные
BEGIN TRANSACTION

    INSERT

    update

    update

    DELETE

COMMIT TRANSACTION

ROLLBACK TRANSACTION

-- 2. Неявные транзакции (SELECT, DELETE, UPDATE, TRUNCATE, CREATE, ALTER, DROP.... )

-- 3. Автоматические











