class ResourceLock {
   public:
    ResourceLock(pthread_mutex_t& mx) : mutex(mx) { pthread_mutex_lock(&mutex); }
    ~ResourceLock() { pthread_mutex_unlock(&mutex); }

   private:
    pthread_mutex_t& mutex;  // ref to mutex of shared resource
};

void f() {
    ...
    {
        ResourceLock lock(myMutex);
        // mach etwas in kritischem Abschnitt

        // Hier wird lock automatisch freigegeben, egal ob der Block
        // ordentlich oder wegen einer Exception verlassen wird.
    }
    ...
}