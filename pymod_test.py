from build.pymod import HeaderMC, CompiledMC, LocalMC

def test_LMC():
    LocalMC(100)
    print("LMC success")

def test_HMC():
    HeaderMC(100)
    print("HMC success")

def test_CMC():
    CompiledMC(2)  # small Matrix doesn't crash
    print("worked up to here, but should crash before displaying `DMC success`")
    CompiledMC(100)  # large Matrix crashes
    print("CMC success")

test_LMC()
test_HMC()
test_CMC()