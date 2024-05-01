// GENERATED CODE - DO NOT MODIFY BY HAND

part of 'AppStore.dart';

mixin _$AppStore on _AppStore, Store {

  late final _$isLoadingAtom =
  Atom(name: '_AppStore.isLoading', context: context);

  @override
  bool get isLoading {
    _$isLoadingAtom.reportRead();
    return super.isLoading;
  }

  @override
  set isLoading(bool value) {
    _$isLoadingAtom.reportWrite(value, super.isLoading, () {
      super.isLoading = value;
    });
  }

  late final _$selectedMenuIndexAtom =
  Atom(name: '_AppStore.selectedMenuIndex', context: context);

  @override
  int get selectedMenuIndex {
    _$selectedMenuIndexAtom.reportRead();
    return super.selectedMenuIndex;
  }

  @override
  set selectedMenuIndex(int value) {
    _$selectedMenuIndexAtom.reportWrite(value, super.selectedMenuIndex, () {
      super.selectedMenuIndex = value;
    });
  }

  late final _$isMenuExpandedAtom =
  Atom(name: '_AppStore.isMenuExpanded', context: context);

  @override
  bool get isMenuExpanded {
    _$isMenuExpandedAtom.reportRead();
    return super.isMenuExpanded;
  }

  @override
  set isMenuExpanded(bool value) {
    _$isMenuExpandedAtom.reportWrite(value, super.isMenuExpanded, () {
      super.isMenuExpanded = value;
    });
  }

  late final _$setLoadingAsyncAction =
  AsyncAction('_AppStore.setLoading', context: context);

  @override
  Future<void> setLoading(bool value) {
    return _$setLoadingAsyncAction.run(() => super.setLoading(value));
  }

  late final _$_AppStoreActionController =
  ActionController(name: '_AppStore', context: context);

  @override
  void setSelectedMenuIndex(int val) {
    final _$actionInfo = _$_AppStoreActionController.startAction(
        name: '_AppStore.setSelectedMenuIndex');
    try {
      return super.setSelectedMenuIndex(val);
    } finally {
      _$_AppStoreActionController.endAction(_$actionInfo);
    }
  }

  @override
  void setExpandedMenu(bool val) {
    final _$actionInfo = _$_AppStoreActionController.startAction(
        name: '_AppStore.setExpandedMenu');
    try {
      return super.setExpandedMenu(val);
    } finally {
      _$_AppStoreActionController.endAction(_$actionInfo);
    }
  }

  @override
  String toString() {
    return '''
isLoggedIn: $isLoggedIn,
isLoading: $isLoading,
selectedMenuIndex: $selectedMenuIndex,
isMenuExpanded: $isMenuExpanded,

    ''';
  }
}
