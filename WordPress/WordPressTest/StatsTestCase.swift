import XCTest
import CoreData
@testable import WordPress

// A thin wrapper round XCTestCase for Stats test to avoid repeating boilerplate.
class StatsTestCase: XCTestCase {

    fileprivate var manager: TestContextManager!

    override func setUp() {
        manager = TestContextManager()
    }

    var mainContext: NSManagedObjectContext {
        return manager.mainContext
    }

    override func tearDown() {
        mainContext.reset()
    }

    @discardableResult func createStatsRecord(in context: NSManagedObjectContext, type: StatsRecordType, date: Date) -> StatsRecord {
        let newRecord = StatsRecord(context: context)
        newRecord.type = type.rawValue
        newRecord.date = date as NSDate

        return newRecord
    }

}
