ALTER TABLE VOTANTES ADD CONSTRAINT CHECK_CORREO CHECK(INSTR(EMAIL, '@')>1 AND INSTR(EMAIL, '.', INSTR(EMAIL, '@'))>INSTR(EMAIL, '@')+1 AND LENGTH(EMAIL)>INSTR(EMAIL, '.', INSTR(EMAIL, '@')));