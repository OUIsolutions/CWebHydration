

CWebHydrationNamespace newCWebHydrationNamespace() {
    CWebHydrationNamespace self = {0};
    self.create_bridge = CWebHyDration_create_bridge;
    self.create_script = CWebHyDration_create_script;
    self.free = CWebHyDration_free;
    self.newHyDration = newCWebHyDration;
    return self;
}